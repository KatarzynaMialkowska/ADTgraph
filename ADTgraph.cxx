#include "ADTgraph.hxx"


int main(){
    graph<std::string,std::string, int>A;
    graph<int,std::string, std::string>B;
    A.addVertex("Warszawa");
    A.setVertexValue("Krakow","A");
    A.setVertexValue("Poznan","B");
    A.setVertexValue("Gdansk","C");

    A.setEdgeValue("Warszawa","Krakow",1);
    A.setEdgeValue("Krakow","Warszawa",2);
    A.setEdgeValue("Poznan","Gdansk",3);   
    A.setEdgeValue("Poznan","Warszawa",6); 
    A.view();
    A.writeDot();

    
    A.dijkstra("Warszawa");
    std::cout<<"=======\n";
    A.dijkstra("Poznan");

     std::cout<<"=======\n";
    A.dijkstra("Krakow");

    //A.getEdgeValue("Warszawa","Krakow"); 

    // B.addVertex(1);
    // B.setVertexValue(2,"A");
    // B.setVertexValue(3,"B");
    // B.setVertexValue(4,"C");

   
    // B.addEdge(1,1);
    // B.addEdge(2,3);
    // B.addEdge(3,1);  
    // std::cout<<"Exist 1-1? : "<<B.adjacent(1,1)<<'\n';
    // std::cout<<"Exist 1-2? : "<<B.adjacent(1,2)<<'\n';
    // B.view(); 
    // B.getVertexValue(2); 

    // B.remove(2);
    // B.view(); 
    // A.setVertexValue("4","D");
    // A.setVertexValue("4","D");
    // A.setVertexValue("4","E");
    // A.setVertexValue("4","AA");
    // A.setVertexValue("1","AA");
    // A.addEdge(1,4);
    // A.addEdge(1,6);
    // A.addEdge(2,3);
    // A.addEdge(3,3);
    // A.setEdgeValue(3,3,2);
    // A.getEdgeValue(3,3); 
    // A.getVertexValue(1); 
  

    // A.neighbours(1);
    // A.remove(1);
    // A.view();
    // A.removeEdge(2,3);
    // A.removeEdge(3,3);
    // A.view();
    // A.addVertex(1,0);
    // A.addVertex(2,0);
    // A.addVertex(3,0);
    // A.addVertex(4,0);
    // A.addVertex(5,0);
    // A.addVertex(6,0);
    // A.addVertex(7,11);
    // A.addVertex(8);
    // A.addVertex(9);


   

    return 0;
}