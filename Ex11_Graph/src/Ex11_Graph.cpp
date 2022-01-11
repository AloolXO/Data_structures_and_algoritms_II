//============================================================================
// Name        : Ex11_Graph.cpp
// Author      : AloolXO
// Version     :
// Copyright   : Ex8 Virtual class
// Description : Hello World in C++, Ansi-style
//============================================================================



     #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    string str(int d)
    {
            int n = 10;
            string s = "";
            while(d != 0)
            {
                    s = char(((d%n)/(n/10))+48) + s;
                    d = d - (d%n);
                    n *= 10;
            }
            return s;
    }



    struct link
    {
            int data;
            link* next;
    };


    class linklist
    {
            private:
                    link* first;
            public:
            bool e;

            linklist ( )
            {
                    first = NULL;
                    e = false;
            }

    void additem ( int d );//добавление элемента
    void display ( );//вывод списка
    bool exist(int x);//проверка вхождения элемента в список
    void makenull();//опустошение списка
    void delitem(int d) ;
    int Putnumberver( );
    };



    int linklist::Putnumberver()
    {
            link* current = new link;
            current = first;
            int d = 0;
            while(current)
            {
                    d += 1;
                    current = current ->next;
            }
            return d;
    }






        void linklist::delitem(int d)
            {
         link* current = new link;
         link* prev = new link;
             int t = 0;

         current = first;
         prev = current;


         while(current)
         {
                     current->data = t;
                            if(t == d)
                            {
                                            prev -> next = current -> next;
                        delete[]current;
                        current = prev -> next;
                            }
                            else
                            {
                           prev = current;
                           current = current->next;
                            }
         }

            }







    void linklist::additem ( int d ) // добавление элемента
    {
      link* newlink = new link;      // выделяем память
      newlink->data = d;             // запоминаем данные
      newlink->next = first;         // запоминаем значение first
      first = newlink;               // first теперь указывает на новый элемент
    }

    void linklist::display ( )
    {
      link* current = first;           // начинаем с первого элемента
      while( current )                 // пока есть данные
      {
        cout << current->data << endl; // печатаем данные
        current = current->next;       // двигаемся к следующему элементу
      }
    }

        bool linklist:: exist(int x)
         {
          link* current = first;
          if (!current) return 0;
          while( current )
          {
                 if (current->data == x)
                 {
                  return 1;
                  break;
                 }
                 current = current->next;
          }

          if (current == NULL)
          return 0;
      }

        void linklist::makenull()
        {
         link* current = first;
         link* deleted = new link;
               while(!(current))
               {
                   deleted = current;
                   current = current->next;
                   delete deleted;
               }
               first = NULL  ;
               cout<<"Linklist is free";
         }


    class Graph



    {
      private:

       linklist adj[1000];

      public:

        Graph ( )
          {  }

        void addedge (int x,int y);
        void addvertex (int x);
        void deledge (int x,int y);
        void delvertex (int x);
        void p(int n);
        void q(int n);
        void d(int x);
        void display ();
        void saves();
        void Load();
        void D1(int x);
        void IsF(int n, int x, int y);
    };

            void Graph::Load()
            {
                    char str[50];


                    int j = 0,i = 0,z = 0;
                    ifstream file("Graph.txt");

                    while(file)
                    {
                            file.getline(str,50);
                            i = static_cast<int>(str[0] - 48);

                                    if(i != -48)
                                    addvertex(i);

                    }
                    file.close();

                    ifstream file1("Graph.txt");
                    while(file1)
                    {
                            file1.getline(str,50);
                            z = static_cast<int>(str[0] - 48);

                            for(int k = 2; k < 50; k++)
                            {
                                    i = static_cast<int>(str[k] - 48);
                                    addedge(z,i);
                            }
                    }
                    file.close();
            }


            void Graph::saves()
            {
                     ofstream file1;

                    for(int i = 1;i <= 1000; i++)
                    {
                              if(adj[i].e == true)
                                     {

                                             file1.open("Граф.txt",std::ios_base::app);
                                             file1<<"Вершина "<<i<<" - ";
                                             file1.close();

                                             file1.open("Graph.txt",std::ios_base::app);
                                             file1<<i<<" ";
                                             file1.close();

                                             adj[i].save();
                                     }
             }
            }

            void Graph::addvertex(int x)
            {

                     if (adj[x].e==false)
                            adj[x].e=true;
                     else
                             cout<<"Такая вершина уже существует"<<endl;
            }



            void Graph::addedge(int x,int y)
            {
                    if ((adj[x].e == true) && (adj[y].e == true) && (adj[x].exist(y) == false) && (adj[y].exist(x)==false) && (x!=y))
                    {
                            adj[x].additem(y);
                            adj[y].additem(x);
                    }
                    /*else
                            cout<<"Ошибка,одна или обе вершины отсутствуют или между ними уже сть ребро"<<endl;*/
            }


            void Graph::display()
            {
                    for (int i = 1; i < 1000; i++)
                    {
                            if (adj[i].e == true)
                            {
                            cout<<"Вершина с номером "<<i<<" - смежные с ней вершины: ";
                            adj[i].display();
                            cout<<endl;
                            }
                    }
            }

            void Graph::deledge (int x,int y)
            {
                     if ((adj[x].e == true) && (adj[y].e == true) && (adj[x].exist(y) == true) && (adj[y].exist(x) == true) && (x!=y))
                    {
                            adj[x].delitem(y);
                            adj[y].delitem(x);
                    }
                    else
                            cout<<"Ошибка"<<endl;
            }


            void Graph::delvertex(int x)
            {

                    if (adj[x].e == true)
                    {
                            adj[x].e = false;
                            adj[x].makenull();

                            for (int i = 1; i < 1000; i++)
                            {
                                    if (adj[i].exist(x) == 1)
                                            adj[i].delitem(x);
                            }
                    }
                    else
                            cout<<"Такая вершина отсутсвует"<<endl;
            }

            void Graph::p(int n)
            {
                    int d = 0;
                    for (int i = 1; i <= n; i++)
                    {
                            if (adj[i].e == true)
                                    d++;
                    }

                    cout<<"В графе существует "<<d<<" вершин"<<endl;
            }

            void Graph::q(int n)
            {
                    int d = 0;
                    for (int i = 1; i <= n; i++)
                    {
                            if (adj[i].e == true)
                             d = d + adj[i].Putnumberver();
                    }

                    cout<<"В графе существует "<<(d/2)<<" ребер"<<endl;
            }

            void Graph::d(int x)
            {
                     cout<<"Степень вершины "<<x<<" равна "<<adj[x].Putnumberver()<<endl;

            }


            void Graph::D1( int x)
                {
                   if (adj[x].e==true)
                      {
                        adj[x].display;
                      }
                      else
                       cout<<"error";


                }

            void Graph::IsF(int n, int x, int y)
            {
                    for (int x = 1; x <=n ;x++)
                    {
                            for (int y = 1; x <=n ;x++)
                            {
                                    if ((adj[x].e == true) && (adj[y].e == true) && (adj[x].exist(y) == true) && (adj[y].exist(x) == true) && (x!=y))
                                            cout<<"Полнота есть"<<endl;
                                    else
                                            cout<<"Полноты нет"<<endl;
                            }
                    }


            }



    int _tmain(int argc, _TCHAR* argv[])
    {
            setlocale(LC_ALL, "Russian");

            Graph G;
            int s = 0,n = 0,x = 0,y = 0,v = 0;


         while(true)
             {

           cout<<"Что вы хотите сделать с графом?"<<endl
              <<"1 - Добавить вершину"<<endl
              <<"2 - Добавить ребро"<<endl
              <<"3 - Удалить вершину"<<endl
              <<"4 - Удалить ребро"<<endl
              <<"5 - Посчитать количество ребер"<<endl
              <<"6 - Посчитать количество вершин"<<endl
              <<"7 - Вывести степень вершины"<<endl
              <<"8 - Вывести граф на экран"<<endl
              <<"9 - Сохранить граф"<<endl
              <<"10 - Загрузить граф"<<endl
              <<"11 - Выйти"<<endl
                      <<"12 - Возвращает список вершин, удалённых на расстояние n от вершины v"<<endl
                      <<"13 - ПРоверка графа на полноту"<<endl;
          cin>>v;



          if(v == 1)
          {
            cout<<"Введите номер новой вершины"<<endl;
            cin>>x;
            G.addvertex(x);
            n++;
          }

          if(v == 2)
          {
            cout<<"Введите номера двух соединяемых вершин "<<endl;
            cin>>x>>y;
            G.addedge(x,y);
          }

          if(v == 3)
          {
            cout<<"Введите номер удаляемой вершины"<<endl;
            cin>>x;
            G.delvertex(x);
          }

          if(v == 4)
          {
            cout<<"Введите номера двух вершин,между которыми вы хотите удалить ребро"<<endl;
            cin>>x>>y;
            G.deledge(x,y);
          }

          if(v == 5)
          {
            G.q(n);
          }

          if(v == 6)
          {
            G.p(n);
          }

          if(v == 7)
          {
            cout<<"Введите номер вершины,степень которой вы хотите вывести "<<endl;
            cin>>x;
            G.d(x);
          }

          if(v == 8)
           G.display();

          if(v == 9)
          {
            G.saves();
          }

          if(v == 10)
          {
                     G.Load();
          }

          if(v == 11)
            break;

              if(v == 12)
              {
                 G.D1(x);
              }

              if(v == 13)
              {
                     G.IsF(n,x,y);
              }
       }




        system("pause");

            return 0;
    }




