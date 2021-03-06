// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_COMMON_ORDER_H_
#define FT_SRC_COMMON_ORDER_H_

#include <map>
#include <string>

#include "core/constants.h"
#include "core/contract.h"
#include "core/protocol.h"

namespace ft {

enum class OrderStatus {
  CREATED = 0,
  SUBMITTING,
  REJECTED,
  NO_TRADED,
  PART_TRADED,
  ALL_TRADED,
  CANCELED,
  CANCEL_REJECTED
};

struct Order {
  OrderReq req;

  // 这个ID是策略发单的时候提供的，使策略能定位其订单，类似于备注
  uint32_t user_order_id;

  // 这个是订单在经纪商的id，提供给用户用于撤单或改单
  uint64_t order_id;

  const Contract* contract = nullptr;
  bool accepted = false;
  int traded_volume = 0;
  int canceled_volume = 0;
  OrderStatus status;
  uint64_t insert_time;
  std::string strategy_id;
};

inline const std::string& to_string(OrderStatus s) {
  static const std::map<OrderStatus, std::string> s_str = {
      {OrderStatus::SUBMITTING, "Submitting"},
      {OrderStatus::REJECTED, "Rejected"},
      {OrderStatus::NO_TRADED, "No traded"},
      {OrderStatus::PART_TRADED, "Part traded"},
      {OrderStatus::ALL_TRADED, "All traded"},
      {OrderStatus::CANCELED, "Canceled"},
      {OrderStatus::CANCEL_REJECTED, "Cancel rejected"}};

  return s_str.find(s)->second;
}

}  // namespace ft

#endif  // FT_SRC_COMMON_ORDER_H_
