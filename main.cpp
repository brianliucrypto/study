#include "data_struct/SeqList.hpp"
#include <iostream>

#include "data_struct/DeLinkList.hpp"
#include "data_struct/LinkList.hpp"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
   DeLinkList<int> list;
    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);
    list.Insert(3, 4);
    list.Display();
    int a;
    list.Delete(3);
    list.Display();
    list.Reverse();
    list.Display();
    return 0;
}