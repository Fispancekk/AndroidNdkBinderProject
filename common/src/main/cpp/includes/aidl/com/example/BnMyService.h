#pragma once

#include "aidl/com/example/IMyService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace example {
class BnMyService : public ::ndk::BnCInterface<IMyService> {
public:
  BnMyService();
  virtual ~BnMyService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace example
}  // namespace com
}  // namespace aidl
