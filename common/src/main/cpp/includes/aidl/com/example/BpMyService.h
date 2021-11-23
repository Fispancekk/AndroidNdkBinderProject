#pragma once

#include "aidl/com/example/IMyService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace example {
class BpMyService : public ::ndk::BpCInterface<IMyService> {
public:
  BpMyService(const ::ndk::SpAIBinder& binder);
  virtual ~BpMyService();

  ::ndk::ScopedAStatus cotrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, std::string* _aidl_return) override;
  ::ndk::ScopedAStatus returnCoTrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, ::aidl::com::example::CotrollerData* _aidl_return) override;
};
}  // namespace example
}  // namespace com
}  // namespace aidl
