/*
 * File:   DFSOrder.h
 * Author: Cuisenaire
 * Labo 2
 * Created on 3. novembre 2014, 08:23
 */


#include <cstdlib>
#include <iostream>
#include <set>
#include "Util.h"
#include "DiGraph.h"
#include "SymbolGraph.h"
#include "TopologicalSort.h"

using namespace std;

//methode permettant de verifier le graphe trie par rapport au fichier d'entree
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
            int w = SG.index(names[i]); // ieme prerequis
            
            if ( positionInOrder[ v ] < positionInOrder [ w ]) {
                cout << "Erreur d'ordre : " << names[0] << " avant " << names[i] << endl;
                ok = false;
            } 
        }
    }
    s.close();
    
    return ok;
}

int main(int argc, const char * argv[]) {

    std::string prerequis1("prerequis.txt");
    std::string prerequis2("prerequis2.txt");
    SymbolGraph<DiGraph> SG1(prerequis1, ',');
    SymbolGraph<DiGraph> SG2(prerequis2, ',');
    std::cout << SG1.G().V() << std::endl;
    std::cout << SG2.G().V() << std::endl;

    DirectedCycle<DiGraph> DC1(SG1.G());
    std::cout << "-------" << std::endl;
    DirectedCycle<DiGraph> DC2(SG2.G());

    if(DC1.HasCycle()) std::cout << "has cycle" << std::endl;
    else std::cout << "has not cycle" << std::endl;
    if(DC2.HasCycle()) std::cout << "has cycle" << std::endl;
    else std::cout << "has not cycle" << std::endl;

    TopologicalSort<DiGraph> TS(SG1.G());
    for(auto i : TS.Order()) {
        std::cout << SG1.symbol(i) << std::endl;
    }
    /* A IMPLEMENTER */
    
    return EXIT_SUCCESS;
}
