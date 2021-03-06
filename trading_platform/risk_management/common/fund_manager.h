// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_RISK_MANAGEMENT_COMMON_FUND_MANAGER_H_
#define FT_SRC_RISK_MANAGEMENT_COMMON_FUND_MANAGER_H_

#include <map>

#include "common/order.h"
#include "core/account.h"
#include "risk_management/risk_rule_interface.h"

namespace ft {

class FundManager : public RiskRuleInterface {
 public:
  bool init(const Config& config, Account* account, Portfolio* portfolio,
            std::map<uint64_t, Order>* order_map,
            const MdSnapshot* md_snapshot) override;

  int check_order_req(const Order* order) override;

  void on_order_sent(const Order* order) override;

  void on_order_traded(const Order* order,
                       const OrderTradedRsp* trade) override;

  void on_order_canceled(const Order* order, int canceled) override;

  void on_order_rejected(const Order* order, int error_code) override;

 private:
  Account* account_{nullptr};
};

}  // namespace ft

#endif  // FT_SRC_RISK_MANAGEMENT_COMMON_FUND_MANAGER_H_
