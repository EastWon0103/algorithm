    // for(int i=0;i<3;i++) {
    //     if(pattern[0]==alpha[i]) {
    //         DFA[i][0] = 1;
    //     } else {
    //         DFA[i][0] = 0;
    //     }
    // }
    // int X = 0;

    // for(int i=1;i<=len;i++) {
    //     for(int j=0;j<3;j++) {
    //         DFA[i][j] = DFA[i][X];
    //     }

    //     int matched = getRow(pattern[i]);
    //     DFA[matched][i] = i;
    //     X = DFA[matched][X];
    // }