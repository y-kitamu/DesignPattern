/*
 * test_abstract_factory.cpp
 *
 * Create Date : 2020-02-25 21:16:09
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "factory/factory.hpp"
#include "factory/link.hpp"
#include "factory/tray.hpp"
#include "factory/page.hpp"

int main(int argc, char ** argv) {
    if (argc != 2) {
        std::cout << "Usage ./<path>/<to>/abstract_factory_test_abstract_factory <class name of concrete>";
        return 0;
    }

    std::shared_ptr<dp::Factory> factory;

    if (argv[0] == "listfactory") {
        factory = dp::Factory::getFactory<dp::ListFactory>();
    }

    std::shared_ptr<dp::Link> asahi = factory->createLink("Asahi", "http://www.asahi.com");
    std::shared_ptr<dp::Link> yomiuri = factory->createLink("Yomiuri", "http://www.yomiuri.com");
    std::shared_ptr<dp::Link> yahoo = factory->createLink("Yahoo", "http://www.yahoo.com");
}
    
