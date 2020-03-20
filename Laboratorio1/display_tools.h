#ifndef DISPLAY_TOOLS_H
#define	DISPLAY_TOOLS_H

#include <iostream>

void showMatrix(Matrix K){
    for(int i=0;i<K.at(0).size();i++){
        cout << "[\t";
        for(int j=0;j<K.size();j++){
            cout << K.at(i).at(j) << "\t";
        }
        cout << "]\n";
    }
}

#endif	/* DISPLAY_TOOLS_H */

