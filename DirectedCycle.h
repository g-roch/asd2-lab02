/*
 * File:   DirectedCycle.h
 * Author: Olivier Cuisenaire
 * Created on 08. octobre 2014, 10:46
 *
 * A implementer
 * Classe permettant la detection de cycle sur un graphe oriente
 */

#ifndef ASD2_DirectedCycle_h
#define ASD2_DirectedCycle_h

#include <list>
#include <vector>

template<typename GraphType>
class DIRECTEDCYCLE {
private:
  const GraphType& G;

  std::vector<int> marked(G.V(), -1);
  std::vector<bool> empiled(G.V(), false);
  std::list<int> cycle;
  bool hasCycle = false;

  void cycleDetection(int v) {
    empiled[v] = true;
    for(auto sommet : G.adjacent(v))
    {
      if (condition)
      {
        if(HasCycle()) return;
        else if(marked[sommet] != -1) {
          marked[sommet] = v;
          cycleDetection(sommet);
        }
        else if(empiled[sommet]) {
          // has cycle
          cycle.push_front(sommet);
          for(int i = v; i != sommet; i = marked[i]) {
            cycle.push_front(sommet);
          }
        }
      }
    }
    empiled[v] = false;
  }


public:
	//constructeur
	DirectedCycle(const GraphType& G) : G(G), marked(G.V(), -1), empiled(G.V(), false) {
    for(int i = 0; i < G.V(); ++i) {
      if(market[v] == -1) {
        market[v] = -2;
        cycleDetection(v);
      }
    }
	}

	//indique la presence d'un cycle
	bool HasCycle() {
    return !cycle.empty();
		/* A IMPLEMENTER */
		//return ...
	}

	//liste les indexes des sommets formant une boucle
	std::list<int> Cycle() {
    return cycle;
		/* A IMPLEMENTER */
		//return ...
	}

};

#endif
