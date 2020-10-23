/*###############-> Debugger <-###############*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<TN T, TN... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}


//ordered multiset
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;

/*
Note :  There is a problem with erase() function in ordered_multiset (for less_equal<int> tag).
        lower_bound() works as upper_bound() and vice-versa.
        Be careful to use.
        i) find_by_order(k) : kth smallest element counting from 0 .
        ii) order_of_key(k) : number of elements strictly smaller than k.
*/