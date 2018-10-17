#include <iostream>
#include "Upper.h"
#include "Intermediate.h"
#include "Base.h"
#include "Proxy.h"
#include "Observer.h"
#include "Mediator.h"

/**
 * Задание 1.
 * Нужно написать шаблонный класс, который в зависимости от переданного параметра
 * будет выполнять роль либо прокси, либо медиатора, либо наблюдателя для двух других классов.
 */

void testProxy() {
    std::cout << std::endl << std::endl << "Test Proxy" << std::endl;
    using inter_type = intermediate::types::Proxy;

    auto proxy = std::make_shared<Proxy>();
    Upper<inter_type > upper(proxy);
    upper.request();
}

void testObserver() {
    std::cout << std::endl << std::endl << "Test Observer" << std::endl;
    using inter_type = intermediate::types::Observer;

    auto observer = std::make_shared<Observer>();
    auto upper1 = new Upper<inter_type>(observer);
    auto upper2 = new Upper<inter_type>(observer);
    observer->subscribe(upper1);
    observer->subscribe(upper2);

    upper1->request();
}

void testMediator() {
    std::cout << std::endl << std::endl << "Test Mediator" << std::endl;
    using inter_type = intermediate::types::Mediator;
    auto mediator = std::make_shared<Mediator<2>>();
    auto upper = new Upper<inter_type>(mediator);
    upper->request();
    upper->request();
    upper->request();
}

int main() {
    testProxy();
    testObserver();
    testMediator();
    return 0;
}