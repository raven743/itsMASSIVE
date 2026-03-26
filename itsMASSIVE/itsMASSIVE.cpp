#include "header.h"

int main()
{
    SingleLinkedList SLlist;

    std::cout << "DOING THE SINGLELINKEDLIST\n\n";

    std::cout << "Starting the first function = adding to the end of the list." << std::endl;
    SLlist.Append(10);
    SLlist.PrintToConsole();
    SLlist.Append(8);
    SLlist.PrintToConsole();
    SLlist.Append(6);
    SLlist.PrintToConsole();
    SLlist.Append(4);
    SLlist.PrintToConsole();

    std::cout << "\n\nStarting the second function = adding to the start." << std::endl;
    SLlist.AddToBegin(9);
    SLlist.PrintToConsole();

    std::cout << "\n\nStarting the third function = deleting from beggining." << std::endl;
    SLlist.RemoveFromBegin();
    SLlist.PrintToConsole();

    std::cout << "\n\nStarting the fourth function = deleting from the end." << std::endl;
    SLlist.RemoveFromEnd();
    SLlist.PrintToConsole();

    std::cout << "\n\nStarting the fifth function = delete completely." << std::endl;
    SLlist.Clear();
    SLlist.PrintToConsole();

    std::cout << "\n\nStarting the sixth function = checking if the value is on the list.";
    std::cout << "Is there 3 on the list? -- " << (SLlist.IsContain(3) ? "Yes" : "No") << std::endl;
    std::cout << "Is there 2 on the list? -- " << (SLlist.IsContain(2) ? "Yes" : "No") << std::endl;

    std::cout << "\n\n\n---------------------------------------------------------\n\n\n" << std::endl;

    Stack stack;
    std::cout << "DOING THE STACK\n\n";

    std::cout << "Starting the first function = adding to the end." << std::endl;
    stack.Add(1);
    stack.PrintToConsole();
    stack.Add(1);
    stack.PrintToConsole();
    stack.Add(0);
    stack.PrintToConsole();
    stack.Add(3);
    stack.PrintToConsole();
    stack.Add(7);
    stack.PrintToConsole();
    stack.Add(9);
    stack.PrintToConsole();

    std::cout << "\n\nStarting the second function = deleting from the end." << std::endl;
    stack.Remove();
    stack.PrintToConsole();

    std::cout << "\n\nStarting the third function = checking the value in the list.";
    std::cout << "Is there 3 on the list? -- " << (stack.IsContain(3) ? "Yes" : "No") << std::endl;
    std::cout << "Is there 2 on the list? -- " << (stack.IsContain(2) ? "Yes" : "No") << std::endl;

    std::cout << "\n\nStarting the forth function = delete completely." << std::endl;
    stack.Clear();
    stack.PrintToConsole();

    std::cout << "\n\n\n---------------------------------------------------------\n\n\n" << std::endl;

    Queue queue;

    std::cout << "DOING THE QUEUE\n\n";

    std::cout << "Starting the first function = adding to the end." << std::endl;
    queue.Add(9);
    queue.PrintToConsole();
    queue.Add(8);
    queue.PrintToConsole();
    queue.Add(7);
    queue.PrintToConsole();
    queue.Add(6);
    queue.PrintToConsole();
    queue.Add(5);
    queue.PrintToConsole();
    queue.Add(4);
    queue.PrintToConsole();

    std::cout << "\n\nStarting the second function = deleting from beggining." << std::endl;
    queue.Remove();
    queue.PrintToConsole();


    std::cout << "\n\nStarting the third function = checking the value in the list.";
    std::cout << "Is there 3 on the list? -- " << (queue.IsContain(3) ? "Yes" : "No") << std::endl;
    std::cout << "Is there 2 on the list? -- " << (queue.IsContain(2) ? "Yes" : "No") << std::endl;

    std::cout << "\n\nStarting the forth function = delete completely." << std::endl;
    queue.Clear();
    queue.PrintToConsole();

    std::cout << "\n\n\n---------------------------------------------------------\n\n\n" << std::endl;

    Array arr;

    std::cout << "DOING THE ARRAY\n\n";
    arr.fillFromKeyboard();
    arr.print();

    std::cout << "\n- Redacting the element -" << endl;
    int index, value;
    std::cout << "Entert the index to change: ";
    std::cin >> index;
    std::cout << "Enter the new value: ";
    std::cin >> value;

    if (arr.edit(index, value)) {
        std::cout << "Element changed." << endl;
        arr.print();
    }

    std::cout << "\n- Adding an element in the end -" << endl;
    std::cout << "Enter the value: ";
    std::cin >> value;

    if (arr.add(value)) {
        std::cout << "Element added!" << endl;
        arr.print();
    }

    std::cout << "\n- Enter the element by index -" << endl;
    std::cout << "Enter the index to add: ";
    std::cin >> index;
    std::cout << "Enter the value: ";
    std::cin >> value;

    if (arr.insertAt(index, value)) {
        std::cout << "Element added." << endl;
        arr.print();
    }

    std::cout << "\n- Deleting elements -" << endl;
    std::cout << "Enter the index for deletion: ";
    std::cin >> index;

    if (arr.removeAt(index)) {
        std::cout << "Element deleted." << endl;
        arr.print();
    }

    std::cout << "\n- Using the [] operator -" << endl;
    std::cout << "Arr[0] = " << arr[0] << endl;
    arr[0] = 999;
    std::cout << "After Arr[0] = 999: ";
    arr.print();

    std::cout << "\n Additional information: " << endl;
    std::cout << "Size: " << arr.getSize() << endl;
    std::cout << "Max size: " << arr.getMaxSize() << endl;
    std::cout << "Is it empty?" << (arr.isEmpty() ? "Yes" : "No") << endl;
    std::cout << "Is it full?" << (arr.isFull() ? "Yes" : "No") << endl;
    std::cout << "Minimal: " << arr.getMin() << endl;
    std::cout << "Max: " << arr.getMax() << endl;
    std::cout << "Sum: " << arr.sum() << endl;
    std::cout << "Arithmetic mean: " << arr.average() << endl;

    std::cout << "\nSorting..." << endl;
    arr.sort();
    std::cout << "Sorting finished: ";
    arr.print();

    std::cout << "\n\n\n---------------------------------------------------------\n\n\n" << std::endl;

    std::cout << "DOING THE DICTIONARY\n\n";
    Dictionary<int, int> dict1;
    dict1.Add(1, 100);
    dict1.Add(2, 200);
    dict1.Add(3, 300);

    std::cout << "Dictionary 1:" << std::endl;
    dict1.Print();
    std::cout << "Size: " << dict1.Count() << std::endl;

    Dictionary<int, double> dict2;
    dict2.Add(1, 1.5);
    dict2.Add(2, 2.7);
    dict2.Add(3, 3.9);

    std::cout << "\nDictionary 2:" << std::endl;
    dict2.Print();

    std::cout << "\nKey 2 value: " << dict2.Get(2) << std::endl;

    dict2.Remove(2);
    std::cout << "Removing key 2:" << std::endl;
    dict2.Print();

    std::cout << "Contains key 1? " << (dict2.ContainsKey(1) ? "Yes" : "No") << std::endl;
    std::cout << "Contains key 5? " << (dict2.ContainsKey(5) ? "Yes" : "No") << std::endl;

    std::cout << "\n\n\n---------------------------------------------------------\n\n\n" << std::endl;

    std::cout << "DOING THE STRING\n\n";

    String s1("Colt");
    String s2(" 1911");
    std::cout << "S1: " << s1 << std::endl;
    std::cout << "S2: " << s2 << std::endl;

    String s3 = s1 + s2;
    std::cout << "S1 + S2: " << s3 << std::endl;

    String s4("BLUE");
    s4 += String(" DAWN");
    std::cout << "S4: " << s4 << std::endl;

    std::cout << "Lenght S1: " << s1.length() << std::endl;

    std::cout << "S1[0]: " << s1[0] << std::endl;

    String s5("DIE");
    String s6("ZOMBI");
    std::cout << "S1 == S5: " << (s1 == s5) << std::endl;
    std::cout << "S1 == S6: " << (s1 == s6) << std::endl;

    String s7 = s1;
    std::cout << "S7 (S1 copy): " << s7 << std::endl;

    s1.append('!');
    std::cout << "S1 after append: " << s1 << std::endl;

    s1.insert(0, '*');
    std::cout << "S1 after insert: " << s1 << std::endl;

    s1.remove(0);
    std::cout << "S1 after remove: " << s1 << std::endl;

    int pos = s3.find('M');
    std::cout << "'M' in S3: " << pos << std::endl;

    String sub = s3.substring(0, 6);
    std::cout << "Line S3[0:6]: " << sub << std::endl;

    s3.clear();
    std::cout << "S3 after clear: \"" << s3 << "\"" << std::endl;
    std::cout << "S3 is empty?? " << s3.isEmpty() << std::endl;

    return 0;
}