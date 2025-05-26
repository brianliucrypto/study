#include "data_struct/SeqList.hpp"
#include <iostream>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    SeqList<int> list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Insert(1, 4); // 在索引1处插入元素4
    list.Remove(2); // 删除索引2处的元素
    list.Display();
    list.Reverse();
    list.Display();
    return 0;
}