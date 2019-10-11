/*
 * File:   main.cpp
 * Author: Cuisenaire
 * Labo 2
 * Created on 3. novembre 2014, 08:23
 *
 * Modified on 11 octobre 2019
 *  By Gabriel Roch, Gwendoline Dössegger, Jean-Luc Blanc 
 */


#include <cstdlib>
#include <iostream>
#include <set>
#include "Util.h"
#include "DiGraph.h"
#include "SymbolGraph.h"
#include "TopologicalSort.h"

using namespace std;

//methode permettant de verifier si le graphe est bien trié par rapport au fichier d'entrée
bool checkOrder(const std::vector<int>& order,
    const SymbolGraph<DiGraph>& SG,
    const std::string& filename,
    char delim) {

  std::vector<int> positionInOrder(order.size());
  for( size_t i = 0; i < order.size(); ++i )
    positionInOrder[order[i]] = int(i);

  bool ok = true;

  std::string line;

  std::ifstream s(filename);
  while (std::getline(s, line))
  {
    auto names = split(line,delim);

    for(size_t i = 1; i < names.size(); ++i) {

      int v = SG.index(names[0]); // module
      int w = SG.index(names[i]); // ième prérequis

      if ( positionInOrder[ v ] < positionInOrder [ w ]) {
        cout << "Erreur d'ordre : " << names[0] << " avant " << names[i] << endl;
        ok = false;
      } 
    }
  }
  s.close();

  return ok;
}

/** 
 * Effecture les tests sur un fichier d'adjacent donné
 * Les sommets sont séparé par des ','
 */
void test(const std::string & filename) {
  SymbolGraph<DiGraph> SG(filename, ',');
  DirectedCycle<DiGraph> DC(SG.G());

  // détecte si le graphe possède un cycle
  if(DC.HasCycle()) {
    std::cout << filename << " n'est pas un DAG" << std::endl;
    std::cout << "Cycle trouvé : " << std::endl;
    for(auto i : DC.Cycle()) {
      std::cout << SG.symbol(i) << " ";
    }
    std::cout << std::endl;
  } else { // Le graph est un DAG
    std::cout << filename << " est un DAG" << std::endl;
    std::cout << "Ordre topologique : " << std::endl;
    TopologicalSort<DiGraph> TS(SG.G());
    for(auto i : TS.Order()) {
      std::cout << SG.symbol(i) << " ";
    }
    std::cout << std::endl;

    if(!checkOrder(TS.Order(), SG, filename, ',')) {
      // Notre ordre n'est pas correct
      std::cerr << "!!!! Erreur dans l'algorithme !!!!" << std::endl;
    }
  }
}

int main() {

  // Test les 2 fichiers
  test("prerequis.txt");
  test("prerequis2.txt");

  return EXIT_SUCCESS;
}
