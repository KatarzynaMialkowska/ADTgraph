#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <iomanip>
#include <fstream>
 
constexpr int M = 5;

template<class  T1, class  T2, class T3>
class graph
{
    struct typeV
    {
        T1 key;
        T2 v_;
        typeV()=default;
        typeV(T1 k, T2 val):key(std::move(k)),v_(std::move(val)){};
        typeV(T1 k):key(std::move(k)){};
        bool operator==(const typeV &other) const{
            if(key!=other.key && v_!=other.v_)return false;
            else return true;
        }
    };
    struct typeE
    {
        bool is;
        T3 v_;
        typeE()=default;
        typeE(bool i, T3 val):is(std::move(i)),v_(std::move(val)){};
        typeE(bool i):is(std::move(i)){};
        bool operator==(const typeE &other) const{
            if(is!=other.is && v_!=other.v_)return false;
            else return true;
        }
    };
    std::vector<std::vector <typeE>> edge;
    std::vector<typeV> vertex;
    public:   
    graph():edge(M,std::vector<typeE>(M)){};     
    inline bool adjacent(T1 x, T1 y){ 
        typeV temp1(x);
        typeV temp2(y);
        if(getID(temp1)!=-1 && getID(temp2)!=-1){      
            size_t row = getID(temp1);
            size_t col = getID(temp2);
        return edge[row][col].is; 
        }else return false;
    }
    inline void neighbours(T1 x){
        //std::vector<typeV> neighbor;
        typeV temp1(x);
        if(getID(temp1)==-1)throw std::out_of_range("none");
        size_t row = getID(temp1);
        std::cout<<"neighbours ["<<x<<"] : \n";
        for(size_t i = 0; i<edge[row].size(); ++i){
            if(edge[row][i].is!=0)std::cout<<i<<" ";
        }
        std::cout<<'\n';
        //return std::move(neighbor);
    }
    inline void setVertexValue(T1 x, T2 v){
        typeV temp(x,v);
        // auto it = std::find(vertex.cbegin(),vertex.cend(),temp);
        // if(it==vertex.end())
            // vertex.push_back(temp);
          if(!find(temp))
            vertex.push_back(temp);
    }
    inline void addVertex(T1 x){
        typeV temp(x);
        if(!find(temp))
            vertex.push_back(temp);
            
    }
    inline void addEdge(T1 x, T1 y){
        typeV temp1(x);
        typeV temp2(y);
        if(getID(temp1)!=(-1) && getID(temp2)!=(-1)){      
        size_t row = getID(temp1);
        size_t col = getID(temp2);
        typeE etemp(false);
        if(edge.size()-1<row){
            size_t old = edge.size();
            edge.resize(row+1);
                for(size_t i = old; i < edge.size(); ++i){
                    edge[i].resize(col+1);
                }
        }
        if(edge[0].size()-1<col){;
            for(size_t i = 0; i < edge.size(); ++i){
                edge[i].resize(col+1);
            }
        }
        edge[row][col].is = true;
        }
        
    }
    inline void setEdgeValue(T1 x, T1 y, T3 v){
        typeV temp1(x);
        typeV temp2(y);
      
        if(getID(temp1)!=-1 && getID(temp2)!=-1){      
        size_t row = getID(temp1);
        size_t col = getID(temp2);
        typeE etemp(false);
        if(edge.size()-1<row){
            size_t old = edge.size();
            edge.resize(row+1);
                for(size_t i = old; i < edge.size(); ++i){
                    edge[i].resize(col+1);
                }
        }
        if(edge[0].size()-1<col){;
            for(size_t i = 0; i < edge.size(); ++i){
                edge[i].resize(col+1);
            }
        }
        edge[row][col].is = true;
        edge[row][col].v_ = v;
        edge[col][row].is = true;
        edge[col][row].v_ = v;
        }
        
    }
    
    inline void view(){
        std::cout<<"|vertex|\n";
        size_t j = 0;
        for(auto i : vertex)
            std::cout<<i.key<<"["<<i.v_<<"]"<<" ";
        std::cout<<'\n';
        std::cout<<"|edge|\n";
        for(size_t row = 0; row < edge.size(); ++row){
            if(j<vertex.size())
                std::cout<<std::setw(10)<<vertex[j].key<<"|";
                else
                std::cout<<std::setw(11)<<'|';
            for(size_t col = 0; col < edge[row].size(); ++col){
                std::cout<<edge[row][col].is<<" ";
            }
            std::cout<<'\n';
            ++j;
        }

    }
    inline T3 getEdgeValue(T1 x, T1 y){
        typeV temp1(x);
        typeV temp2(y);
        if(getID(temp1)!=-1 && getID(temp2)!=-1){      
            size_t row = getID(temp1);
            size_t col = getID(temp2);
            std::cout<<"value edge "<<x<<"-"<<y<<": "<<edge[row][col].v_ <<'\n';
            return std::move(edge[row][col].v_);
        }else throw std::out_of_range("none");
    }
    inline T2 getVertexValue(T1 x){
        typeV temp(x);
        if(getID(temp)==-1)throw std::out_of_range("none");
        std::cout<<"value vertex "<<x<<": "<<vertex[getID(temp)].v_<<'\n';
        return std::move(vertex[getID(temp)].v_);
    }
    inline bool find(typeV x){
            for(auto i : vertex)
                if(i.key==x.key)return true;
            return false;
    }
    inline int getID(typeV x){
        if(!find(x))return std::move(-1);
        int temp = 0;
            for(auto i : vertex){
                if(i.key==x.key)break;
                ++temp;       
            }             
        return std::move(temp);
    }
    inline void remove(T1 x){
        typeV temp(x);
        if(getID(temp)!=-1){
            size_t row = getID(temp);
            // for(size_t i = 0; i<edge[row].size(); ++i){
            //     edge[row][i].is=0;   
            // }
            //edge[row].erase(edge[row].begin()+i);
            edge.erase(edge.begin()+row);
            // for(int i=0;i<indices.size();i++) //Now, delete them
            //     v.erase(v.begin()+indices[i]);
            vertex.erase(vertex.begin()+(getID(temp)));
        }
    }
    inline void removeEdge(T1 x, T1 y){ edge[x][y].is=0; }

    inline void writeDot(){
        std::fstream file;
        file.open("Graph.gv", std::ios::out);
        file<<"digraph{\n";
        for(size_t row = 0; row < edge.size(); ++row){
            for(size_t col = 0; col < edge[row].size(); ++col){
                if(edge[row][col].is!=0)
                file<<"\t"<<vertex[row].key<<" -> "<<vertex[col].key<<";\n";
            }
        }
        file<<"}\n";
        file.close();
    }

        inline void dijkstra(T1 x) {
        int inf = 214748364;
        typeV temp1(x);
        size_t start{0}, count{0}, min_distance{0}, nextnode{0};
        if(getID(temp1)!=-1)      
            start = getID(temp1);

        std::vector<std::vector<size_t>>cost(vertex.size(),std::vector<size_t>(vertex.size(),inf));
        std::vector<size_t> distance(vertex.size(), 0), pred(vertex.size(), 0), visited(vertex.size(), 0);

        for(size_t i=0; i<vertex.size(); i++)
            for(size_t j=0; j<vertex.size(); j++)
                if(edge[i][j].is == true)
                    cost[i][j] = edge[i][j].v_;



        for(size_t i = 0; i<vertex.size(); i++) {
            distance[i] = cost[start][i];
            pred[i] = start;

        }
        distance[start] = 0;
        visited[start] = 1;
        count = 1;

        while(count < vertex.size()-1) {
            min_distance = inf;
            for(size_t i=0; i<vertex.size(); i++)
                if(distance[i] < min_distance && !visited[i]) {
                    min_distance = distance[i];
                    nextnode = i;
                }
            visited[nextnode] = 1;
            for(size_t i=0; i<vertex.size(); i++)
                if(!visited[i])
                    if(min_distance + cost[nextnode][i] < distance[i]) {
                        distance[i] = min_distance + cost[nextnode][i];
                        pred[i] = nextnode;
                    }
            count++;
        }
    for(size_t i = 0;i<vertex.size();i++)
        if(i != start) {
                std::cout<<"from " << vertex[start].key << " to "<< vertex[i].key <<" = "<< distance[i] << '\n';
                std::cout <<'\t'<< vertex[i].key;
                size_t j = i;
                do {
                    j = pred[j];
                    std::cout<<"<-"<< vertex[j].key;
                }while(j!=start);
                std::cout<<'\n';
            }
        
    }
};

