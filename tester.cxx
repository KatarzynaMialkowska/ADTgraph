#include "ADTgraph.hxx"
#include "ADTgraphList.hxx"
#include "gnuplot.hxx"
#include <chrono>
#include <fstream>
#include <cmath>
#include <cstdio>



void test_1k(std::vector<int> x,std::vector<int> y, std::vector<int> v);
void test_5k(std::vector<int> x,std::vector<int> y, std::vector<int> v);
void test_10k(std::vector<int> x,std::vector<int> y, std::vector<int> v);
void test_15k(std::vector<int> x,std::vector<int> y, std::vector<int> v);
void test_20k(std::vector<int> x,std::vector<int> y, std::vector<int> v);

std::ofstream setGraphAdd, setGraphAddList;
std::string setGaPlot("setGraphAdd.dat");
std::string setGaLPlot("setGraphAddList.dat");
std::string name_graphs("graphs");
std::string type("pdf");


int main() {

    /*dane potrzebne do wykresów*/
    setGraphAdd.open (setGaPlot, std::ios::out | std::ios::app); 
    setGraphAddList.open (setGaLPlot, std::ios::out | std::ios::app); 

    int N,x_,y_,v_;
    std::cin >> N;
    std::vector<int>x;
    std::vector<int>y;
    std::vector<int>v;

    for(int i=0; i<N; i++){
        std::cin >> x_;
        x.push_back(x_);
        std::cin >> y_;
        y.push_back(y_);
        std::cin >> v_;
        v.push_back(v_);
    }

    test_1k(x, y, v);
    test_5k(x, y, v);
    test_10k(x, y, v);
    test_15k(x, y, v);
    test_20k(x, y, v);


   /*Tworzenie wykresu*/
    gnuplot p;
    std::string setA("\'./" + setGaPlot + "\' u 1:2 w l");
    std::string setAL("\'./" + setGaLPlot + "\' u 1:2 w l");


    p("set terminal " + type);
    p("set output \"" + name_graphs + '.' + type + "\""); 
    p("set xlabel 'data'");
    p("set ylabel 't/s'");
    p("set title 'Add graph vs Add graph list'");

        p("set xrange [0:20000]");
        p("set yrange [0:50]");
    p("plot " + setA +  " , " +  setAL);
 

    setGraphAdd.close();
 
    setGraphAddList.close();


    return 0;
}

void test_1k(std::vector<int> x,std::vector<int> y, std::vector<int> v) {
    graph<int,int,int>A;
    graphList<int,int,int>B;
    int N = 1000;
    std::cout << "\t-TEST 1000 n-\n";

    /*test Add*/
    auto Astart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        A.setVertexValue(x[i], v[i]);
        A.setVertexValue(y[i], v[i]);
        A.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Aend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> AddElapsed = Aend - Astart;
    std::cerr << "Add elapsed time[s] =" << AddElapsed.count() << std::endl;
        setGraphAdd << N << '\t' << AddElapsed.count() << '\n';
   // A.view();
    
      /*test List Add*/
    auto Lstart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        B.setVertexValue(x[i], v[i]);
        B.setVertexValue(y[i], v[i]);
        B.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> LAddElapsed = Lend - Lstart;
    std::cerr << "Add elapsed time[s] =" << LAddElapsed.count() << std::endl;
        setGraphAddList << N << '\t' << LAddElapsed.count() << '\n';
   // A.view();
}

void test_5k(std::vector<int> x,std::vector<int> y, std::vector<int> v) {
    graph<int,int,int>A;
    graphList<int,int,int>B;
    int N = 5000;
    std::cout << "\t-TEST 5000 n-\n";


    /*test Add*/
    auto Astart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        A.setVertexValue(x[i], v[i]);
        A.setVertexValue(y[i], v[i]);
        A.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Aend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> AddElapsed = Aend - Astart;
    std::cerr << "Add elapsed time[s] =" << AddElapsed.count() << std::endl;
        setGraphAdd << N << '\t' << AddElapsed.count() << '\n';

      /*test List Add*/
    auto Lstart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        B.setVertexValue(x[i], v[i]);
        B.setVertexValue(y[i], v[i]);
        B.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> LAddElapsed = Lend - Lstart;
    std::cerr << "Add elapsed time[s] =" << LAddElapsed.count() << std::endl;
        setGraphAddList << N << '\t' << LAddElapsed.count() << '\n';
   // A.view();
}

void test_10k(std::vector<int> x,std::vector<int> y, std::vector<int> v) {
    graph<int,int,int>A;
    graphList<int,int,int>B;
    int N = 10000;
    std::cout << "\t-TEST 10000 n-\n";


    /*test Add*/
    auto Astart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        A.setVertexValue(x[i], v[i]);
        A.setVertexValue(y[i], v[i]);
        A.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Aend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> AddElapsed = Aend - Astart;
    std::cerr << "Add elapsed time[s] =" << AddElapsed.count() << std::endl;
        setGraphAdd << N << '\t' << AddElapsed.count() << '\n';

    
     /*test List Add*/
    auto Lstart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        B.setVertexValue(x[i], v[i]);
        B.setVertexValue(y[i], v[i]);
        B.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> LAddElapsed = Lend - Lstart;
    std::cerr << "Add elapsed time[s] =" << LAddElapsed.count() << std::endl;
        setGraphAddList << N << '\t' << LAddElapsed.count() << '\n';
   // A.view();
}

void test_15k(std::vector<int> x,std::vector<int> y, std::vector<int> v) {
    graph<int,int,int>A;
    graphList<int,int,int>B;
    int N = 15000;
    std::cout << "\t-TEST 15000 n-\n";


    /*test Add*/
    auto Astart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        A.setVertexValue(x[i], v[i]);
        A.setVertexValue(y[i], v[i]);
        A.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Aend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> AddElapsed = Aend - Astart;
    std::cerr << "Add elapsed time[s] =" << AddElapsed.count() << std::endl;
        setGraphAdd << N << '\t' << AddElapsed.count() << '\n';

    
      /*test List Add*/
    auto Lstart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        B.setVertexValue(x[i], v[i]);
        B.setVertexValue(y[i], v[i]);
        B.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> LAddElapsed = Lend - Lstart;
    std::cerr << "Add elapsed time[s] =" << LAddElapsed.count() << std::endl;
        setGraphAddList << N << '\t' << LAddElapsed.count() << '\n';
   // A.view();
}


void test_20k(std::vector<int> x,std::vector<int> y, std::vector<int> v) {
    graph<int,int,int>A;
    graphList<int,int,int>B;
    int N = 20000;
    std::cout << "\t-TEST 20000 n-\n";


    /*test Add*/
    auto Astart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        A.setVertexValue(x[i], v[i]);
        A.setVertexValue(y[i], v[i]);
        A.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Aend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> AddElapsed = Aend - Astart;
    std::cerr << "Add elapsed time[s] =" << AddElapsed.count() << std::endl;
        setGraphAdd << N << '\t' << AddElapsed.count() << '\n';

    
    /*test List Add*/
    auto Lstart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<N; i++){
        B.setVertexValue(x[i], v[i]);
        B.setVertexValue(y[i], v[i]);
        B.setEdgeValue(x[i], y[i], v[i]);
    }
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> LAddElapsed = Lend - Lstart;
    std::cerr << "Add elapsed time[s] =" << LAddElapsed.count() << std::endl;
        setGraphAddList << N << '\t' << LAddElapsed.count() << '\n';
   // A.view();
}
