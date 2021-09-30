#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<utility>
#include <list>
#include <iterator>


template<class  T1, class  T2, class T3>
class graphList
{
    struct typeV
    {
        T1 key;
        T2 v_;
        std::list<std::pair<T1, T3>> list;

        typeV()=default;
        typeV(T1 k): key(std::move(k)){};
        typeV(T1 k, T2 v): key(std::move(k)), v_(std::move(v)){};
        typeV(const typeV &other): key(std::move(other.key)), v_(std::move(other.v_)), list(std::move(other.list)){}
        T1 getKey(){ return key; }
        bool operator==(const typeV &other) const{
            if(key!=other.key && v_!=other.v_)return false;
            else return true;
        }
        typeV& operator=(typeV* other){
            key = other.key;
            v_ = other.v_; 
            list = other.list;
            return *this;
        }
    };
    std::vector<typeV> vertex;

    public: 
    graphList()=default;

    //check if an edge exsist between vertex x and y   
    inline bool adjacent(T1 x, T1 y){
        for(auto i : vertex){
            if(i->key == x){
                for(auto j : i.list)
                    if(j.first == y) return true;
                }
            }
        return false;
    }
    //return vertex's neighbors 
    inline void neighbours(T1 x){
        for(auto i : vertex){
            if(i->key == x){
                for(auto j : i.list)
                    std::cout<<"-"<<j.first<<"["<<j.second<<"]";
                }
                std::cout<<'\n';
            }
    }
    //set vertex with value
    inline void setVertexValue(T1 x, T2 v){
        if(!find(x)){     
            typeV temp(x,v);
            vertex.push_back(temp);
        }
    }
    //add vertex without value
    inline void addVertex(T1 x){
        if(!find(x)){
            typeV temp(x);
            vertex.push_back(temp);
        }
    }
    //add edge without value
    inline void addEdge(T1 x, T1 y){
  
        int t1{getID(x)}, t2{getID(y)};
        if(t1==-1 || t2==-1)
            throw std::out_of_range("ERROR: addEdge()");

        if(!check(t1,y) && !check(t2,x)){        
            std::pair<T1,T3>p1,p2;
            p1.first = x;
            p2.first = y;
            vertex[t1].list.push_back(p2);
            if(t1!=t2)
            vertex[t2].list.push_back(p1);
        }

    }
    //checks if vertex in list repeats multiple times
    inline bool check(int id, T1 v){
        for(auto i : vertex[id].list)
            if(i.first == v) return true; 
        return false;
    }
    //set edge with weight
    inline void setEdgeValue(T1 x, T1 y, T3 v){
        addVertex(x);
        addVertex(y);
        int t1{getID(x)}, t2{getID(y)};
        if(!check((t1),y) && !check(t2,x)){        
            std::pair<T1,T3>p1{x,v},p2{y,v};
            vertex[t1].list.push_back(p2);
            if(t1!=t2)
            vertex[t2].list.push_back(p1);
        } 
    }
    //get edge weight
    inline T3 getEdgeValue(T1 x, T1 y){
        int t1{getID(x)};
        if(t1==-1)
            throw std::out_of_range("ERROR: getEdgeValue() - id");
        for(auto i : vertex[t1].list)
            if(i.first == y) return std::move(i.second);

        throw std::out_of_range("ERROR: getEdgeValue()");
    }
    //get vertex value
    inline T2 getVertexValue(T1 x){
        int t1{getID(x)};
        if(t1==-1)
            throw std::out_of_range("ERROR: getVertexValue()");
        return std::move(vertex[t1].v_);
    }
    //check if vertex exsist
    inline bool find(T1 x){
            for(auto i : vertex)
                if(i.key==x)return true;
            return false;
    }
    //get id vector of vertex
    inline int getID(T1 x){
        if(!find(x))return std::move(-1);
        int temp = 0;
            for(auto i : vertex){
                if(i.key==x)break;
                ++temp;       
            }             
        return std::move(temp);
    }
    //remove vertex from vector and list
    inline void removeVertex(T1 x){
        int id = getID(x);
        if(id!=-1){
        std::cout<<"========\n";
        typename std::list<std::pair<T1, T3>>::iterator range_begin;
            for(size_t i = 0; i<vertex.size(); i++){
            range_begin = vertex[i].list.begin();
                for(auto j : vertex[i].list){
                    if(j.first == x){
                        vertex[i].list.erase(range_begin);
                        break;
                    } 
                    ++range_begin;
                }         
            }

             vertex.erase(vertex.begin()+id);
        }
    }
    //remove edge from list
    inline void removeEdge(T1 x, T1 y){ 

        int t1{getID(x)}, t2{getID(y)};
        if((t1==-1) || (t2==-1)){
             throw std::out_of_range("ERROR: removeEdge()");
        }
        std::cout<<"========\n";
  
        typename std::list<std::pair<T1, T3>>::iterator range_begin = vertex[t1].list.begin();
            for(auto j : vertex[t1].list){
                if(j.first == y){
                    vertex[t1].list.erase(range_begin);
                    break;
                }
                ++range_begin;
            }
               
        range_begin = vertex[t2].list.begin();
            for(auto j : vertex[t2].list){ 
                if(j.first == x){
                     vertex[t2].list.erase(range_begin);
                     break;
                }
                ++range_begin;
                
               
            }
    

    }

    inline void view(){
        for(auto i : vertex){
            std::cout<<"["<<i.key<<"] ["<<i.v_<<"]-";
            for(auto j : i.list)
                std::cout<<"->"<<j.first<<"["<<j.second<<"]";
         std::cout<<'\n';
        }
    }
};

