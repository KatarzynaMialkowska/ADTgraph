#include "ADTgraphList.hxx"


int main(){
    graphList<std::string,std::string, int>A;

    A.addVertex("Warszawa");
    A.addVertex("Krakow");
    A.addVertex("Poznan");
    A.addVertex("Gdansk");

    A.addEdge("Warszawa","Krakow");
    A.addEdge("Warszawa","Gdansk");
    A.setEdgeValue("Warszawa","Poznan",2);
    A.addEdge("Warszawa","Warszawa");
     A.view();
    A.removeVertex("Warszawa");

    A.view();
   

    return 0;
}