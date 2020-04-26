
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <fstream>
//#define DEBUG
#define DE
using namespace std;

#ifdef DEBUG
    ofstream debugfile;
#endif 
#ifdef DE
    ofstream debugfile;
#endif 

void print_queue(queue<int> que);
class PeopleNode
{
public:
    //variable
    string name;
    int erdosNumber;
    int indexOfPeopleNode;
    //function
    PeopleNode(string name, int indexOfPeopleNode)
    {
        this->name = name;
        this->indexOfPeopleNode = indexOfPeopleNode;
        this->erdosNumber = -999;
    }
    void to_string(){
        #ifdef DEBUG
            debugfile << "name:" ;
            debugfile.width(20);
            debugfile << this->name ;
            debugfile.width(20);
            debugfile<<"index:" << this->indexOfPeopleNode ;
            debugfile.width(20);
            debugfile  << "erdosNumber:" << this->erdosNumber <<endl;
        #endif 
        
    }
    
};
typedef PeopleNode *PeopleNodePtr;

class PeopleNodeList
{

public:
    //variable
    int totalIndexOfPeopleNodeList;
    vector<PeopleNodePtr> list;
    vector<PeopleNodePtr> actualList;
    vector<bool> visited;

    //function
    PeopleNodeList()
    {
        this->totalIndexOfPeopleNodeList = 0;
        this->insertPeopleNode("Erdos, P.");
    }
    void insertPeopleNode(string name)
    {
        int alreadyInArray=0;
        for(int j=0;j<this->list.size();j++){
            if(this->list[j]->name == name)alreadyInArray=1;
        }
        if(!alreadyInArray){
            PeopleNodePtr tmp = new PeopleNode(name, this->totalIndexOfPeopleNodeList++);
            this->list.push_back(tmp);
            this->visited.push_back(false);
        }
    }
    void insertPeopleNodeToActualList(string name){
        PeopleNodePtr tmp = new PeopleNode(name ,this->totalIndexOfPeopleNodeList);
        this->actualList.push_back(tmp);
    }
    int listSize()
    {
        return this->list.size();
    }
    int searchNodeIndex(string name)
    {
        int resultIndex;
        bool hasFound=0;
        for (int i = 0; i < this->list.size(); i++)
        {
            if (this->list[i]->name == name){
                resultIndex=i;
                hasFound=1;
            }
        }
        if(hasFound==0){
            resultIndex= -1;
        }
        return resultIndex;
    }
    PeopleNodePtr getNodePtrByIndex(int Index)
    {
        return this->list[Index];
    }
    PeopleNodePtr getNodePtrByName(string name)
    {
        for(int i=0;i<this->list.size();i++){
            if(name == this->list[i]->name){
                return this->list[i];
            }

        }
    }

    void printActualListErodosNum(){
        PeopleNodePtr tmpNode;
        for(int i=0;i<this->actualList.size();i++){
            tmpNode= this->getNodePtrByName(this->actualList[i]->name);
            if(tmpNode->erdosNumber==-999){
                cout << tmpNode->name << " infinity" << endl;
                #ifdef DE
                    debugfile << tmpNode->name << " infinity" << endl;
                #endif
                #ifdef DEBUG
                    debugfile << tmpNode->name << " infinity" << endl;
                #endif
            }
            else{
                #ifdef DEBUG
                    debugfile<< tmpNode->name << tmpNode->erdosNumber << endl;
                #endif
                #ifdef DE
                    debugfile<< tmpNode->name <<" " << tmpNode->erdosNumber << endl;
                #endif
                cout << tmpNode->name <<" " << tmpNode->erdosNumber << endl;
                
            }
        }

    }
    void printAllErdosNum(){
        PeopleNodePtr tmpNode;
        for(int i=1;i<this->list.size();i++){
            tmpNode=this->list[i];
            if(tmpNode->erdosNumber==-999){
                cout << tmpNode->name << " infinity" << endl;
                #ifdef DE
                    debugfile << tmpNode->name << " infinity" << endl;
                #endif
                #ifdef DEBUG
                    debugfile << tmpNode->name << " infinity" << endl;
                #endif
            }
            else{
                #ifdef DEBUG
                    debugfile<< tmpNode->name << tmpNode->erdosNumber << endl;
                #endif
                #ifdef DE
                    debugfile<< tmpNode->name <<" " << tmpNode->erdosNumber << endl;
                #endif
                cout << tmpNode->name <<" " << tmpNode->erdosNumber << endl;
                
            }
        }

    }
    void to_string(){
        #ifdef DEBUG
            for(int i=0;i<this->list.size();i++){
                this->list[i]->to_string();
            }
            for(int i=0;i<this->list.size();i++){
                debugfile << "index:" << i << " " << this->visited[i]<< " ";
            }
            debugfile << endl;
        #endif 
    }
};

class AdjacencyMatrix
{
public:
    int **matrix;
    int columnSize;
    AdjacencyMatrix(int columnSize)
    {
        this->columnSize = columnSize;
        this->matrix = new int *[columnSize];
        for (int i = 0; i < columnSize; i++)
        {
            this->matrix[i] = new int[columnSize];
        }
        //initial
        for(int i=0;i<this->columnSize;i++){
            for(int j=0;j<this->columnSize;j++){
                this->matrix[i][j]=-999;
            }
        }
    }
    void connectNode(int node1Index, int node2Index)
    {
        /*
        **(matrix + (this->columnSize * node1Index) + node2Index) = 1;
        *(matrix + (this->columnSize * node2Index) + node1Index) = 1;
        */

        #ifdef DEBUG
            debugfile << "connect" << node1Index <<" " << node2Index << endl;
        #endif
        matrix[node1Index][node2Index]=1;
        matrix[node2Index][node1Index]=1;
    }
    int checkIfConnect(int node1Index, int node2Index)
    {
        //return *(matrix + (this->columnSize * node1Index) + node2Index);
        #ifdef DEBUG
            debugfile << node1Index << " " << node2Index << endl;
            debugfile << matrix[node1Index][node2Index] << endl;
        #endif

        return matrix[node1Index][node2Index];
    }
    void to_string(PeopleNodeList& peopleNodeList){
        
        #ifdef DEBUG
            debugfile <<"columnsize:" << this->columnSize << endl;
            debugfile << "                    ";

            for(int i=0;i<this->columnSize;i++){
                debugfile.width(20);
                debugfile << peopleNodeList.getNodePtrByIndex(i)->name;
            }
            debugfile << endl;
            //print matrix

            /*
            ios state(nullptr);
            state.copyfmt(cout);
            */

            for(int i=0;i<this->columnSize;i++){
                debugfile.width(2);
                debugfile << i;
                debugfile.width(20);
                debugfile << peopleNodeList.getNodePtrByIndex(i)->name;
                for(int j=0;j<this->columnSize;j++){
                    debugfile.width(20);
                    debugfile << this->matrix[i][j];
                }
                debugfile<< endl;
            }

        #endif 
        
    }
};

class Queue
{
public:
    queue<int> que;
    void bfs(PeopleNodeList &peopleNodeList, AdjacencyMatrix &adjMatrix, int startIndex)
    {
        

        int parentIndex, childIndex;
        //visit first node
        PeopleNodePtr parentNode,childNode;
        parentNode= peopleNodeList.getNodePtrByIndex(startIndex);
        parentNode->erdosNumber = 0;
        peopleNodeList.visited[startIndex]=true;

        this->que.push(startIndex);
        while (!this->que.empty())
        {
            
            #ifdef DEBUG
                debugfile << "---------------------------bfs interation---------------------" << endl;
                this->to_string();
                peopleNodeList.to_string();
            #endif
            //visit parnet node
            parentIndex = this->que.front();
            this->que.pop();
            parentNode= peopleNodeList.getNodePtrByIndex(parentIndex);

            //add adj node to queue
            for (int i = 0; i < adjMatrix.columnSize ; i++)
            {
                if(!peopleNodeList.visited[i]){
                    childNode= peopleNodeList.getNodePtrByIndex(i);
                    //如果connect才執行
                    if (adjMatrix.checkIfConnect(parentIndex, i)==1)
                    {
                        #ifdef DEBUG
                            adjMatrix.to_string(peopleNodeList);
                            debugfile << adjMatrix.checkIfConnect(parentIndex,i) << endl;
                        #endif
                        peopleNodeList.visited[i]=true;
                        childNode->erdosNumber = parentNode->erdosNumber + 1;
                        que.push(i);
                    }

                }
            
            }
        }
    }
    void to_string(){
        print_queue(this->que);
    }
    

};
void print_queue(queue<int> que){
    #ifdef DEBUG
        debugfile << "queue content:"  << endl;
        while(!que.empty()){
            debugfile << que.front() << " " ;
            que.pop();
        }
        debugfile << endl;
    #endif 

}
void cutNameFromPaperAndInsertToPeopleNodeList(PeopleNodeList& peopleNodeList,vector<string> tmpPaperName){
    //把名字切出來
    for(int i=0;i<tmpPaperName.size();i++){
        string tmp,firstName,lastName;
        stringstream ss(tmpPaperName[i]);
        getline(ss, tmp, ':');
        ss.str("");
        ss.clear();
        ss << tmp;
        //先把文件的人名都存起來到一個陣列
        while (getline(ss, firstName, ','))
        {
            
            getline(ss, lastName, ',');
            string name=firstName+','+lastName;
            peopleNodeList.insertPeopleNode(name);
            //因為後面的人名前面都有一個空白,把它吃掉
            ss.ignore();
        }

    }

}
int main(void)
{
    #ifdef DEBUG
        debugfile.open("erods_deubg.dat", ios::out | ios::trunc );
    #endif
    #ifdef DE
        debugfile.open("erods_deubg_standard_test", ios::out | ios::trunc );
    #endif

    int scenarioCount;
    cin >> scenarioCount;
    int sCount=1;

    while (sCount++ <= scenarioCount)
    {
        cout << "Scenario " << sCount -1<< endl;
        #ifdef DE
            debugfile << "Scenario " << sCount -1 << endl;
        #endif
        int paperCount, peopleCount;
        PeopleNodeList peopleNodeList;
        
        vector<string> tmpPaperName, tmpPeopleName;
        tmpPaperName.clear();
        tmpPeopleName.clear();
        string tmp;
        string firstName, lastName;
        int tmp1,tmp2;

        cin >> paperCount >> peopleCount;
        cin.ignore();

        //將前面論文幾列存入vector中等之後在解析
        tmpPaperName.assign(paperCount, "");
        for (int i = 0; i < paperCount; i++)
        {
            getline(cin,tmpPaperName[i]);
        }
        //根據後面得人名創見node
        for (int i = 0; i < peopleCount; i++)
        {
            getline(cin,tmp);
            peopleNodeList.insertPeopleNode(tmp);
            peopleNodeList.insertPeopleNodeToActualList(tmp);
        }
        peopleCount=peopleNodeList.list.size();
        cutNameFromPaperAndInsertToPeopleNodeList(peopleNodeList,tmpPaperName);
        AdjacencyMatrix adjMatrix(peopleNodeList.list.size());
        //處理前面存起來的文件
        for (int i = 0; i < paperCount; i++)
        {
            tmpPeopleName.clear();
            #ifdef DEBUG
                debugfile <<"paperindex:" << i << "++++++++++++++++new paper++++++++++++++++" << endl;
                debugfile << tmpPaperName[i]<<endl;
            #endif
            //把名字切出來
            stringstream ss(tmpPaperName[i]);
            getline(ss, tmp, ':');
            ss.str("");
            ss.clear();
            ss << tmp;
            //先把文件的人名都存起來到一個陣列
            while (getline(ss, firstName, ','))
            {
                
                getline(ss, lastName, ',');
                tmpPeopleName.push_back(firstName + "," + lastName);
                //因為後面的人名前面都有一個空白,把它吃掉
                ss.ignore();
            }
            //根據得到的人名做全連接
            #ifdef DEBUG
                debugfile << "tmpPeopleName" << endl;
                
                for (int i = 0; i < tmpPeopleName.size(); i++)
                {
                    debugfile << tmpPeopleName[i] << endl;
                }
                peopleNodeList.to_string();
            #endif

            for (int j = 0; j < tmpPeopleName.size(); j++)
            {
                for (int k = 0; k < tmpPeopleName.size(); k++)
                {
                    if (j != k)
                    {
                        #ifdef DEBUG
                                debugfile << tmpPeopleName[j] << " ";
                                debugfile << tmpPeopleName[k] << endl;
                        #endif
                        tmp1=peopleNodeList.searchNodeIndex(tmpPeopleName[j]);
                        tmp2=peopleNodeList.searchNodeIndex(tmpPeopleName[k]);
                        if( tmp1>=0 && tmp2>=0){
                            adjMatrix.connectNode(tmp1,tmp2);
                        }
                    }

                }
            }
            #ifdef DEBUG
                debugfile << "after connect" << endl;
                adjMatrix.to_string(peopleNodeList);
            #endif

        }
        Queue que;

        que.bfs(peopleNodeList,adjMatrix,0);
        #ifdef DEBUG
            peopleNodeList.to_string();
        #endif
        peopleNodeList.printActualListErodosNum();
    }
    #ifdef DEBUG
        debugfile.close();
    #endif
    #ifdef DE
        debugfile.close();
    #endif
}
