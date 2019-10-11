/*
 * File:   DirectedCycle.h
 * Author: Olivier Cuisenaire
 * Created on 08. octobre 2014, 10:46
 *
 * Modified on 11 octobre 2019
 *  By Gabriel Roch, Gwendoline Dössegger, Jean-Luc Blanc 
 */

#ifndef ASD2_DirectedCycle_h
#define ASD2_DirectedCycle_h

#include <list>
#include <vector>
template<typename GraphType>
class DirectedCycle {
  private:
    const GraphType& G;

    std::vector<int> marked;
    std::vector<bool> empiled;
    std::list<int> cycle;

    
    /**
     * @brief Methode de recherche de cycle
     * @param v sommet depuis lequel ont veut détecter un cycle
     * @return true si il y a un cycle, sinon false
     */
    bool cycleDetection(int v) {
      empiled[v] = true;
      for(auto sommet : G.adjacent(v))
      {
         //Si le sommet n'est pas marqué
        if(marked[sommet] == -1) {
          marked[sommet] = v;
          if(cycleDetection(sommet))
            return true;
        }
         // possède un cycle
        else if(empiled[sommet]) {
          cycle.push_front(sommet);
          for(int i = v; i != sommet; i = marked[i]) {
            cycle.push_front(i);
          }
          return true;
        }
      }
      empiled[v] = false;
      return false;
    }


  public:
    
     /**
      * @brief Construit et recherche les cycles
      * @param G graphe dont on veut détecter les cycles
      */
    DirectedCycle(const GraphType& G) : G(G), marked(G.V(), -1), empiled(G.V(), false) {
      for(int i = 0; i < G.V(); ++i) {
        if(marked[i] == -1) {
          marked[i] = i;
          if(cycleDetection(i)) 
            break;
        }
      }
    }

    
    /**
     * @brief indique la presence d'un cycle
     * @return renvoie true si il y a un cycle, sinon renvoie false
     */
    bool HasCycle() const {
      return !cycle.empty();
    }

    
    /**
     * @brief liste les indexes des sommets formant une boucle
     * @return permet de récupérer la liste des cycles
     */
    std::list<int> Cycle() {
      return cycle;
    }

};

#endif
