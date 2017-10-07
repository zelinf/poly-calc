#pragma once

#include "BiOperator.h"

namespace Zelinf {
namespace PolyCalc {
namespace App {
namespace Expression {
namespace Operators {

class Minus : public BiOperator {
public:
    int64_t precedence() override {
        return 1;
    }

    bool leftAssoc() override {
        return true;
    }

    std::shared_ptr<Service::Polynomial>
    apply(std::shared_ptr<Service::Polynomial> lhs, std::shared_ptr<Service::Polynomial> rhs) override;
};

}
}
}
}
}