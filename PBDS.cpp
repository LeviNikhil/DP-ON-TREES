If you want to access elements of a set/multiset with their indices or want to find out the position of an element, use policy-based data structure(pbds).

First copy-paste these lines in your code.

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
//order_of_key = number of elements lesser than the key
//find_by_order = iterator of element at the given index

Now, you can create a set by
pbds st;

All the commands of usual set will also work here the same (there is an exception I'll talk about in the end).

How, to get the index of an element?

use this command

int index = st.order_of_key(element);

order_of_key gives the count of number of elements lesser than the given element.

How, to get the element at a give index?
Use find_by_order command like this

int element = *(st.find_by_order(index));

find_by_order gives the iterator of element at the given index.
So, if iterator is itr, we get the element by using * operator i.e. (*itr).


Above implementation will give you a set.
How to get multiset?
Just change less to less_equal in typedef part i.e.
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


Now, here is the exception.
Erase doesn't work properly in multiset. So, what to do?
We can use lower_bound, upper_bound to get the iterator and then delete the iterator. But here is a catch:

lower_bound works as upper_bound, and upper_bound works as lower_bound.

So, to delete and element:
Use these commands.
auto it = st.upper_bound(element);
st.erase(it);


Now, how to create a set in descending order?
change less to greater, that's it.
