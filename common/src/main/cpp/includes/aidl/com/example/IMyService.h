#pragma once

#include <android/binder_interface_utils.h>

#include <android/binder_parcel_utils.h>
#include "ComplexType.h"
#include "CotrollerData.h"

namespace aidl {
namespace com {
namespace example {
class IMyService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IMyService();
  virtual ~IMyService();



  static std::shared_ptr<IMyService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IMyService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IMyService>* instance);
  static bool setDefaultImpl(std::shared_ptr<IMyService> impl);
  static const std::shared_ptr<IMyService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus cotrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus returnCoTrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, ::aidl::com::example::CotrollerData* _aidl_return) = 0;
private:
  static std::shared_ptr<IMyService> default_impl;
};
class IMyServiceDefault : public IMyService {
public:
  ::ndk::ScopedAStatus cotrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, std::string* _aidl_return) override;
  ::ndk::ScopedAStatus returnCoTrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, ::aidl::com::example::CotrollerData* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace example
}  // namespace com
}  // namespace aidl
