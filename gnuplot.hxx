#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <iostream>
#include <string>


class gnuplot{ 

    FILE *pipe;
    
    public:
        gnuplot();
        ~gnuplot();
        void operator()(const std::string & command);

};

gnuplot::gnuplot(){
    pipe = popen("gnuplot","w");
    if(!pipe)
        std::cerr<<("Gnuplot not found. Please install Gnuplot.");
}

gnuplot::~gnuplot(){
    fprintf(pipe, "exit\n");
    pclose(pipe);
}

void gnuplot::operator()(const std::string & command){
    fprintf(pipe, "%s\n", command.c_str());
    fflush(pipe);
}

#endif