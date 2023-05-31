#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include "float.h"

template<class T>
void print(std::vector<T> &container) {
    std::cout << std::endl << "{ ";
    for (auto itr : container) {
        std::cout << itr << ", ";
    }
    std::cout << "}" << std::endl << std::endl;
}
template<class T>
void print(std::list<T> &container) {
    std::cout << std::endl << "{ ";
    for (auto itr : container) {
        std::cout << itr << ", ";
    }
    std::cout << "}" << std::endl << std::endl;
}

//vector
//list
//float
/*В программе № 1 выполнить следующее:
1. Создать объект-контейнер в соответствии  с вариантом задания и заполнить его данными, тип которых определяется вариантом задания.
2. Просмотреть контейнер.
3. Изменить контейнер, удалив из него одни элементы и заменив другие.
4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
5. Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
6. Изменить первый контейнер, удалив из него n элементов после заданного и добавив затем в него все элементы из второго контейнера.
7. Просмотреть первый  и второй контейнеры.
*/

void program1() {
    std::vector<float> container;
    container.push_back(12.3); container.push_back(0.42); container.push_back(-12.3); container.push_back(66.6); container.push_back(22.82);
    print(container);

    container.erase(container.begin()+3);
    container.erase(container.begin()+1);
    container.insert(container.begin(), 13.2);

    print(container);

    std::vector<float> container1;
    container1.push_back(10.1); container1.push_back(543.8997); container1.push_back(12.7); container1.push_back(34.2); container1.push_back(90.9);
    print(container1);

    int b = 0, n = 2;
    container.erase(container.begin() + b, container.begin() + b + n);
    print(container);

    for (auto itr : container1) {
        container.push_back(itr);
    }
    print(container);
}
/*В программе № 2 выполнить то же самое, но для данных пользовательского типа.*/
void program2() {
    std::vector<Float> container;
    container.push_back(12.3); container.push_back(0.42); container.push_back(-12.3); container.push_back(66.6); container.push_back(22.82);
    print(container);

    container.erase(container.begin()+3);
    container.erase(container.begin()+1);
    container.insert(container.begin(), 13.2);

    print(container);

    std::vector<Float> container1;
    container1.push_back(10.1); container1.push_back(543.8997); container1.push_back(12.7); container1.push_back(34.2); container1.push_back(90.9);
    print(container1);

    int b = 0, n = 2;
    container.erase(container.begin() + b, container.begin() + b + n);
    print(container);

    for (auto itr : container1) {
        container.push_back(itr);
    }
    print(container);
}
/*В программе № 3 выполнить следующее:
1. Создать контейнер, содержащий объекты пользовательского типа. Тип контейнера выбирается в соответствии с вариантом задания.
2. Отсортировать его по убыванию элементов.
3. Просмотреть контейнер.
4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер. Тип второго контейнера определяется вариантом задания.
6. Просмотреть второй контейнер.
7. Отсортировать первый и второй контейнеры по возрастанию элементов.
8. Просмотреть их.
9. Получить третий контейнер путем слияния первых двух.
10. Просмотреть третий контейнер.
11 .Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.
12.Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.
*/
void program3() {
    std::vector<Float> container;
    container.push_back(12.3); container.push_back(0.42); container.push_back(-12.3); container.push_back(66.6); container.push_back(22.82);

    std::sort(container.rbegin(), container.rend());
    print(container);

//    auto find = std::binary_search(container.begin(), container.end(), 0.42,
//                       [] (const Float l, const Float r) { return l > r; });
    std::vector<Float> containerSecond(container.size());
    std::remove_copy_if(container.begin(), container.end(), containerSecond.begin(), [] (const Float i) {
        return (i.value < 10);
    });

    std::list<Float> secondList;
    for (auto itr : containerSecond) {
        secondList.push_back(itr);
    }
    print(secondList);

    std::sort(container.begin(), container.end());
    std::sort(containerSecond.begin(), containerSecond.end());

    for (auto itr : containerSecond) {
        secondList.pop_front();
        secondList.push_back(itr);
    }
    print(container);
    print(containerSecond);

    std::vector<Float> merged(container.size() + containerSecond.size());
    std::merge(container.begin(), container.end(), containerSecond.begin(),
               containerSecond.end(), merged.begin());
    print(merged);

    std::vector<Float> found(merged.size());

    std::remove_copy_if(merged.begin(), merged.end(), found.begin(), [] (const Float i) {
        return (i.value < 10);
    });

    int count = 0;
    for (auto itr : found) {
        if (!itr.value == 0) {
            count++;
        }
    }
    print(found);

    std:: cout << count << std::endl;
}


int main() {
    program1();
    std::cout << "---------------------" << std::endl;
    program2();
    std::cout << "---------------------" << std::endl;
    program3();
    return 0;
}
