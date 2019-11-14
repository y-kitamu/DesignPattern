/*
 */

#ifndef AGGREGATE_HPP__
#define AGGREGATE_HPP__

#include "iterator.hpp"

namespace dp {

class Aggregate {
  public:
    // 仮想デストラクタにより、shape が多態的に delete されたときに、
    // 派生クラスの正しいデストラクタが呼び出されることが保証される。
    // さもなくば、リソースリーク(解放漏れ)の好機となる。???
    virtual ~Aggregate();
    virtual Iterator iterator();
};

}

#endif // AGGREGATE_HPP__
