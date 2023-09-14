#include <bits/stdc++.h>
using namespace std;
#define MEM_SIZE 30000


int main(int argc,char **argv){
    // for(int i=0;i<argc;i++){
    //     printf("%s\n",argv[i]);
    // }
    char mem[MEM_SIZE];
    memset(mem,0,MEM_SIZE);
    int data_ptr=0;
    for(int chunk=1;chunk<argc;chunk++){
        int ptr=0;
        while(argv[chunk][ptr]!='\0'){
            char cur=argv[chunk][ptr];
            cerr<<cur<<" "<<ptr<<" "<<data_ptr<<" "<<(int)mem[data_ptr]<<endl;
            ptr++;
            switch(cur){
                case '>':
                    data_ptr++;
                    break;
                case '<':
                    data_ptr--;
                    break;
                case '+':
                    // cout<<"hereeeeeeeeeeeeeeeeeeeeeee\n";
                    mem[data_ptr]++;
                    break;
                case '-':
                    mem[data_ptr]--;
                    break;
                case '.':
                    cout<<"heereeeeeeeeeeeeeeee\n";
                    printf("%d",data_ptr);
                    printf("%c", 48+mem[data_ptr]);
                    break;
                case ',':
                    scanf("%c", &mem[data_ptr]);
                    break;
                case '[':
                    if(mem[data_ptr]==0){
                        int cnt=0;
                        while(true){
                            if(cnt==0 && argv[chunk][ptr]==']'){
                                ptr++;
                                break;
                            }
                            else if(argv[chunk][ptr]=='['){
                                cnt++;
                            }
                            else if(argv[chunk][ptr]==']'){
                                cnt--;
                            }
                            ptr++;
                            if(argv[chunk][ptr]=='\0'){
                                ptr=0;
                                chunk++;
                            }
                        }
                    }
                    break;
                case ']':
                    if(mem[data_ptr]!=0){
                        int cnt=0;
                        ptr-=2;
                        while(true){
                            // cerr<<"ptr= "<<ptr<<endl;
                            if(cnt==0 && argv[chunk][ptr]=='['){
                                ptr++;
                                break;
                            }
                            else if(argv[chunk][ptr]=='['){
                                cnt++;
                            }
                            else if(argv[chunk][ptr]==']'){
                                cnt--;
                            }
                            ptr--;
                            if(ptr<0){
                                chunk--;
                                ptr=strlen(argv[chunk])-1;
                            }
                        }
                    }
                    break;
                default:
                    continue;
            }
        }
    }
    return 0;
}