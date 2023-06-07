#include <iostream>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
void write_file(vector<string>v,string path,int append)
{
    auto status=ios::in|ios::out|ios::app;
    if(!append)
        status=ios::in|ios::out|ios::trunc;
    fstream file(path.c_str(),status);
    if(file.fail())
        cout<<"can't open file\n";
    for(int i=0; i<v.size(); i++)
        file<<v[i];
    file<<"\n";
    file.close();
}
vector<string> read_file(string path)
{
    vector<string>lines;
    fstream read(path.c_str(),ios::in|ios::out|ios::app);
    string line;
    while(getline(read,line))
    {
        lines.push_back(line);
    }
    return lines;
}
vector<string>split(string line)
{
    string comma=",";
    vector<string>words;
    istringstream iss(line);
    int pos=int(line.find(comma));
    string sub;
    while(pos!=-1)
    {
        sub=line.substr(0,pos);
        words.push_back(sub);
        line.erase(0,pos+comma.length());
        pos=int(line.find(comma));
    }
    return words;
}
int test_choice(int l,int h)
{
    int c;
    cin>>c;
    while(c<l || c>h)
    {
        cout<<"please enter number in range ( "<<l<<" : "<<h<<") :";
        cin>>c;
    }
    return c;
}
int to_int(string s)
{
    istringstream iss(s);
    int num;
    iss>>num;
    return num;
}
class user
{
protected:
    string user_name;
    string password;
    string name;
    string email;
    //string stats;
    //string isadmin;
public:
    user():
        user_name(""),password(""),name(""),email("")
    {
    }
    vector<string> users(const string & line)
    {
        vector<string>v=split(line);
        set_user_name(v[0]);
        set_password(v[1]);
        set_name(v[2]);
        set_email(v[3]);
       // set_isadmin(v[4]);
        return v;
    }
    void new_user(string u)
    {
        set_user_name(u);
        string test;
        cout<<"enter password : ";
        cin>>test;
        set_password(test);
        cout<<"enter your name : ";
        getline(cin,test);
          getline(cin,test);
        set_name(test);
        cout<<"enter email : ";
        cin>>test;
        set_email(test);
       /* cout<<"\nAdmin or customer choose (1 or 0) : ";
        int ad=test_choice(0,1);
        set_isadmin(to_string(ad));*/
    }
    string get_string()
    {
        ostringstream oss;
    oss<<get_user_name()<<","<<get_password()<<","<<get_name()<<","<<get_email()<<",";
        return oss.str();
    }
    void set_user_name(string u_n)
    {
        this->user_name=u_n;
    }
    string get_user_name()const
    {
        return this->user_name;
    }
    void set_password(string pass)
    {
        this->password=pass;
    }
    string get_password()
    {
        return this->password;
    }
    void set_name(string n)
    {
        this->name=n;
    }
    string get_name()
    {
        return this->name;
    }
    void set_email(string em)
    {
        this->email=em;
    }
    string get_email()
    {
        return this->email;
    }
  /*  void set_isadmin(string is)
    {
        this->isadmin=is;
    }
    string get_isadmin()
    {
        return this->isadmin;
    }*/
};
class book
{
private:
    string book_name;
    string book_athour;
    vector<string>pages;
public:
    book():
        book_name(""),book_athour("")
    {
    }
    book(string b)
    {
        vector<string>info=split(b);
        set_book_name(info[0]);
        set_book_athour(info[1]);
        for(int i=2; i<info.size(); ++i)
            pages.push_back(info[i]);
    }
    string book_string(){
    ostringstream oss;
    oss<<get_book_name()<<","<<get_book_athour()<<",";
    for(int i=0;i<pages.size();++i)
    oss<<pages[i]<<",";
    return oss.str();
    }
    void new_book(string n){
    string test;
     set_book_name(n);
     cout<<"enter athour name : ";
     cin>>test;
     set_book_athour(test);
     int num_page=0;
     cout<<"enter how many bages : ";
     cin>>num_page;
     for(int i=0;i<num_page;++i){
      cout<<"enter page "<<i+1<<" : \n";
     getline(cin,test);
     if(!i)
     getline(cin,test);
     pages.push_back(test);
     }
    }
    void set_book_name(string name)
    {
        this->book_name=name;
    }
    string get_book_name()
    {
        return this->book_name;
    }
    void set_book_athour(string name)
    {
        this->book_athour=name;
    }
    string get_book_athour()
    {
        return this->book_athour;
    }
    vector<string>get_page(){
    return pages;
    }

};
class admin:public user
{
private:
    int num_added_book;
public:
    admin():num_added_book(0)
    {

    }
    admin (const string &line){
        vector<string>v=users(line);
        num_added_book=to_int(v[4]);
    }
    void view_profile()
    {
    cout<<"user_name : "<<get_user_name()<<endl;
cout<<"name : "<<get_name()<<endl;
cout<<"email : "<<get_email()<<endl;
cout<<"number of books added with you  : "<<get_num_book()<<endl;
    }
    string get_num_book(){
    return to_string(num_added_book);
    }
    void set_num_book(int x){
    this->num_added_book=x;
    }
};
class customar:public user
{
private :
    int last_page;
    string last_book;
    string tm;
public:
    customar():
        last_page(0),last_book(""),tm("")
    {
    }
    customar(const string &line)
        {
        vector<string>v=users(line);
        //last_page=to_int(v[4]);
        //last_book=v[5];
        set_last_page(to_int(v[4]));
       // cout<<"\\\\\\\\\\\\\\"<<to_int(v[4])<<endl;
        set_last_book(v[5]);
        tm=v[6];
        }
    void view_profile()
    {
cout<<"user_name : "<<get_user_name()<<endl;
cout<<"name : "<<get_name()<<endl;
cout<<"email : "<<get_email()<<endl;
cout<<"last viewed book : "<<get_last_book()<<endl;
    }
    void set_time(string t1)
    {
     this->tm=t1;
    }
    string get_time(){
    return this->tm;
    }
    string get_last_page(){
    return to_string(this->last_page);
    }
    void set_last_page(int x){
    this->last_page=x;
    }
    string get_last_book(){
    return this->last_book;
    }
    void set_last_book(string x){
    last_book=x;
    }
};
class manage_user
{
private:
    string cur_user_name;
    string password;
    //map<string,user>users_data;
    map<string,admin>admins;
    map<string,customar>customars;
public:
    manage_user():
        cur_user_name(""),password("")
    {
        load_data();
    }
    void load_data()
    {
        vector<string>v=read_file("user.txt");
        vector<string>v2=read_file("admin.txt");
        for(auto &it:v2)
        {
            admin d(it);
            admins[d.get_user_name()]=d;
        }
        for(auto &it:v)
        {
            customar c(it);
            customars[c.get_user_name()]=c;
        }
    }
    map<string,admin>& get_admins(){
    return admins;
    }
    map<string,customar>& get_customar(){
    return customars;
    }
    bool test_admin(string us){
     if(admins.count(us))return true;
     else return false;
    }
    void enter_system()
    {
        cout<<"\t1: log in\n";
        cout<<"\t2: sign up\n enter number in range(1:2): ";
        int choice=test_choice(1,2);
        if(choice==1)
            Do_login();
        else{
            Do_signup();
        updata_data(admins[cur_user_name],1);
        }
       /* manage_books m();
        if(test_admin(cur_user_name))
            m.manage_books(admins[cur_user_name]);
        else m.manage_books(customars[cur_user_name]);
            */
    }
    void Do_login()
    {
        cout<<"\n enter user name : ";
        string test;
        cin>>test;
        while(!admins.count(test)&&!customars.count(test))
        {
            cout<<"this user name is unfined try anthor one : ";
            cin>>test;
        }
        cur_user_name=test;
        string test_pass;
         cout<<"\n enter password : ";
        cin>>test_pass;
        if( admins.count(test) ){
        while(admins[cur_user_name].get_password()!=test_pass)
        {
            cout<<"wrong password try agian : ";
            cin>>test_pass;
        }
        }
        else{
        while(customars[cur_user_name].get_password()!=test_pass)
        {
            cout<<"wrong password try agian : ";
            cin>>test_pass;
        }
        }
    }
    void Do_signup()
    {
        cout<<"sign as admin or customar ( 1 : 0 )";
        int choice=test_choice(0,1);
        string test;
        cout<<"enter user name : ";
        cin>>test;
        while(admins.count(test) || customars.count(test))
        {
            cout<<"this user name is invalid try anthor one : ";
            cin>>test;
        }
        if(choice){
                admin d1;
        d1.new_user(test);
        cur_user_name=d1.get_user_name();
        admins[cur_user_name]=d1;
       // updata_data(d1,1);
        }
        else{
             customar c1;
        c1.new_user(test);
        cur_user_name=c1.get_user_name();
        customars[cur_user_name]=c1;
        //updata_data(c1,1);
        }
    }
    void updata_data(admin &s ,int ap)
    {
        ostringstream oss;
        oss<<s.get_string()<<s.get_num_book()<<",";
        string line=oss.str();
        vector<string>lines(1,line);
       // lines.push_back(s.get_num_added());
        write_file(lines,"admin.txt",ap);
    }
     void updata_data(customar &s,int ap)
    {
        ostringstream oss;
        oss<<s.get_string()<<s.get_last_page()<<","<<s.get_last_book()<<","<<s.get_time()<<",";
        string line=oss.str();
        vector<string>lines(1,line);
        //lines.push_back(s.get_last_page());
        write_file(lines,"user.txt",ap);
    }
  void view_profile(){
  if(test_admin(cur_user_name))admins[cur_user_name].view_profile();
  else customars[cur_user_name].view_profile();
  }
  string get_cur_user(){
  return cur_user_name;
  }
};
class manage_books{
private:
string book_name;
map<string,book>books_data;
int current_page;
public:
    manage_books():current_page(0),book_name(""){
    load_books();
    }
    //manage_books(admin &d):d1(d){
    //admin_menu();
    //}
   // manage_books(customar &c){
   // customar_menu();
   // }
    void load_books(){
        books_data.clear();
    vector<string>v=read_file("books.txt");
    for(auto it:v){
        book b1(it);
        books_data[b1.get_book_name()]=b1;
    }
    }
    void updata_all(){
        int x=0;
    for(auto it:books_data){
        if(x++==0)
            updata_book(it.second,0);
        else updata_book(it.second,1);
    }
    }
    void updata_book(book &b,int ap){
        string line=b.book_string();
        vector<string>v(1,line);
        write_file(v,"books.txt",ap);
    }
    void list_book(customar &c){
     for(auto const &pair : books_data){
        cout<<pair.first<<endl;
     }
   //  read_book(c);
    }
    void add_book(admin &d){
      string test;
        cout<<"enter book name : ";
     cin>>test;
     while(books_data.count(test)){
        cout<<"this book added already \n";
        cin>>test;
     }
     book k1;
     k1.new_book(test);
     books_data[k1.get_book_name()]=k1;
     d.set_num_book(to_int(d.get_num_book())+1);
    }
      void read_book(customar &c){
          string test;
          cout<<"enter book name without wrong : ";
          cin>>test;
          while(!books_data.count(test)){
            cout<<"this book don't found try again or enter -1 to close : ";
            cin>>test;
          }
          if(test=="-1")return;
    //current_page=to_int(c.get_last_page());
    cout<<"book name : "<<books_data[test].get_book_name()<<endl;
    cout<<"book athour : "<<books_data[test].get_book_athour()<<endl;
    if(test==c.get_last_book()){current_page=to_int(c.get_last_page());
        cout<<"history of seesion : "<<c.get_time()<<endl;
}
    else current_page=0;
         c.set_last_book(test);
    vector<string>pages=books_data[test].get_page();
    view_pages(current_page,pages);
    c.set_last_page(current_page);
    time_t c_t=time(NULL);
    string tm=ctime(&c_t);
    c.set_time(tm);
      }
      void view_last_page(customar &c){
    cout<<"book name : "<<books_data[c.get_last_book()].get_book_name()<<endl;
    cout<<"book athour : "<<books_data[c.get_last_book()].get_book_athour()<<endl;
    cout<<"history of seesion : "<<c.get_time()<<endl;
        vector<string>pages=books_data[c.get_last_book()].get_page();
        current_page=to_int(c.get_last_page());
        //cout<<"*************"<<c.get_last_page()<<endl;
        view_pages(this->current_page,pages);
        c.set_last_page(current_page);
        time_t c_t=time(NULL);
    string tm=ctime(&c_t);
    c.set_time(tm);
      }
      void view_pages(int num,vector<string>pages){
         // this->current_page=num;
       for(;num<pages.size() && num>=0;){
            cout<<"page number : "<<num+1<<endl;
        cout<<pages[num]<<endl;
        cout<<"enter 1 to next page or -1 to previos page or 0 to close :\n";
        int choice=test_choice(-1,1);
        if(num==0 && choice==-1){
            cout<<"this is the first page \n";
        continue;}
        if(choice==1)
            num++;
        else if(choice==-1)
            num--;
        else break;
        if(num==pages.size()-1 && choice==1){
                set_current_page(0);
            cout<<"this is last page thank to complete reading \n";
            break;
        }
       set_current_page(num);
    }
      }
      void set_current_page(int x){
      current_page=x;
      }
  /*  void admin_menu(admin &d){
    cout<<"menu : \n";
    cout<<"1 : Add a book \n";
    cout<<"2 : view profile \n";
    cout<<"3 : log out";
    int choice=test_choice(1,3);
    if(choice==1)
        add_book();
    else if(choice==2)
        d.view_profile();
        else
    }*/

};
class book_reader_system{
  private:
      manage_user users;
      manage_books books;
      map<string,customar>cust;
      map<string,admin>adm;
  public:
  book_reader_system(){
    // users.load_data();
       cust=users.get_customar();
         adm=users.get_admins();
     }
    void run()
    {
        users.enter_system();
        // cust=users.get_customar();
        // adm=users.get_admins();
         if(users.test_admin(users.get_cur_user()))
            admin_menu();
            else
            customar_menu();
            update_data();
       // cout<<cust[users.get_cur_user()].get_last_book()<<endl;
       // cout<<cust[users.get_cur_user()].get_last_page()<<endl;
        run();
    }
     void admin_menu(){
    cout<<"menu : \n";
    cout<<"1 : Add a book \n";
    cout<<"2 : view profile \n";
    cout<<"3 : log out\n";
    int choice=test_choice(1,3);
    if(choice==1)
        books.add_book(adm[users.get_cur_user()]);
    else if(choice==2)
        adm[users.get_cur_user()].view_profile();
        else return;
            admin_menu();
    }
    void customar_menu(){
    cout<<"menu : \n";
    cout<<"1 : list system books\n";
    cout<<"2 : view current reading session\n";
    cout<<"3 : view profile \n";
    cout<<"4 : log out \n";
      int choice=test_choice(1,4);
    if(choice==1){
           // cout<<"************"<<cust[users.get_cur_user()].get_last_page()<<endl;
        books.list_book(cust[users.get_cur_user()]);
        books.read_book(cust[users.get_cur_user()]);
    }
    else if(choice==2)
        books.view_last_page(cust[users.get_cur_user()]);
    else if(choice==3)
        cust[users.get_cur_user()].view_profile();
         else return;
         customar_menu();
    }
    void update_data(){
        int x=0;
    for(auto it:adm){
        if(x++==0)
        users.updata_data(it.second,0);
     else users.updata_data(it.second,1);
    }
    x=0;
    for(auto it:cust){
     if(x++==0)
        users.updata_data(it.second,0);
     else users.updata_data(it.second,1);
    }
    books.updata_all();
    }
};
int main()
{
    book_reader_system s;
    s.run();
    return 0;
}
