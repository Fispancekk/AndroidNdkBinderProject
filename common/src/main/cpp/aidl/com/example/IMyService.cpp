#include <aidl/com/example/BpMyService.h>
#include <aidl/com/example/BnMyService.h>
#include <aidl/com/example/IMyService.h>

namespace aidl {
namespace com {
namespace example {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnMyService> _aidl_impl = std::static_pointer_cast<BnMyService>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*cotrollerData*/): {
      ::aidl::com::example::CotrollerData in_aCotrollerObject;
      std::string _aidl_return;

      _aidl_ret_status = (&in_aCotrollerObject)->readFromParcel(_aidl_in);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->cotrollerData(in_aCotrollerObject, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*returnCoTrollerData*/): {
      ::aidl::com::example::CotrollerData in_aCotrollerObject;
      ::aidl::com::example::CotrollerData _aidl_return;

      _aidl_ret_status = (&in_aCotrollerObject)->readFromParcel(_aidl_in);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->returnCoTrollerData(in_aCotrollerObject, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = (_aidl_return).writeToParcel(_aidl_out);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
};

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IMyService::descriptor, _aidl_onTransact);

BpMyService::BpMyService(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpMyService::~BpMyService() {}

::ndk::ScopedAStatus BpMyService::cotrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = (in_aCotrollerObject).writeToParcel(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*cotrollerData*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0);
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IMyService::getDefaultImpl()) {
    return IMyService::getDefaultImpl()->cotrollerData(in_aCotrollerObject, _aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = ::ndk::AParcel_readString(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpMyService::returnCoTrollerData(const ::aidl::com::example::CotrollerData& in_aCotrollerObject, ::aidl::com::example::CotrollerData* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = (in_aCotrollerObject).writeToParcel(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*returnCoTrollerData*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0);
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IMyService::getDefaultImpl()) {
    return IMyService::getDefaultImpl()->returnCoTrollerData(in_aCotrollerObject, _aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = (_aidl_return)->readFromParcel(_aidl_out.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnMyService
BnMyService::BnMyService() {}
BnMyService::~BnMyService() {}
::ndk::SpAIBinder BnMyService::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  return ::ndk::SpAIBinder(binder);
}
// Source for IMyService
const char* IMyService::descriptor = "com.example.IMyService";
IMyService::IMyService() {}
IMyService::~IMyService() {}


std::shared_ptr<IMyService> IMyService::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IMyService>(interface);
  }
  return (new BpMyService(binder))->ref<IMyService>();
}

binder_status_t IMyService::writeToParcel(AParcel* parcel, const std::shared_ptr<IMyService>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IMyService::readFromParcel(const AParcel* parcel, std::shared_ptr<IMyService>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IMyService::fromBinder(binder);
  return STATUS_OK;
}
bool IMyService::setDefaultImpl(std::shared_ptr<IMyService> impl) {
  if (!IMyService::default_impl && impl) {
    IMyService::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IMyService>& IMyService::getDefaultImpl() {
  return IMyService::default_impl;
}
std::shared_ptr<IMyService> IMyService::default_impl = nullptr;
::ndk::ScopedAStatus IMyServiceDefault::cotrollerData(const ::aidl::com::example::CotrollerData& /*in_aCotrollerObject*/, std::string* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IMyServiceDefault::returnCoTrollerData(const ::aidl::com::example::CotrollerData& /*in_aCotrollerObject*/, ::aidl::com::example::CotrollerData* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IMyServiceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IMyServiceDefault::isRemote() {
  return false;
}
}  // namespace example
}  // namespace com
}  // namespace aidl
