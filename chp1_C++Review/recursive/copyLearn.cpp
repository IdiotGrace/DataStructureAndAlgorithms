#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    typedef vector<int> IntVector;
    typedef istream_iterator<int> IstreamItr;
    typedef ostream_iterator<int> OstreamItr;
    typedef back_insert_iterator<IntVector> BackInsItr;

    IntVector myvector;
    // 从标准输入设备读入整数
	// 直到输入的是非整型数据为止 请输入整数序列，按任意非数字键并回车结束输入
    cout << "Please input element: " << endl;
    copy(IstreamItr(cin), IstreamItr(), BackInsItr(myvector));
    //输出容器里的所有元素，元素之间用空格隔开
    cout << "Output : " << endl;
    copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));
    cout << endl;

    int myints[] = {10, 20, 30, 40, 50, 60, 70};
    //用法一：将数组myints中的七个元素复制到myvector容器中
    copy(myints, myints+7, ostream_iterator<int>(cout, " "));
    cout << endl;
    //用法二：将数组myints中的元素向左移动一位
    copy(myints+1, myints+7, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;

}