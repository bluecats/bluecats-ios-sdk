Pod::Spec.new do |s|
  s.name     = 'BlueCatsSDK'
  s.version  = '0.1.2'
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
              All text and design is copyright © 2013-2014 BlueCats Australia Pty Ltd.

              All rights reserved.

              https://bluecats.com/tos/
    LICENSE
  }
  s.summary  = 'BlueCatsSDK for micro-location.'
  s.homepage = 'http://www.bluecats.com'
  s.authors   = { 'BlueCats' => 'theteam@bluecats.com' }
  s.source   = { :git => 'https://github.com/bluecats/bluecats-ios-sdk.git', :tag => '0.1.2' }
  s.platform = :ios, '7.0'
  s.source_files = 'Headers/*.h'
  s.preserve_paths = 'libBlueCatsSDK.a'
  s.library = 'BlueCatsSDK'
  
  s.requires_arc = true
  s.ios.deployment_target = '7.0'
  s.frameworks = 'SystemConfiguration', 'CoreBluetooth', 'MobileCoreServices', 'CoreGraphics', 'CoreLocation', 'AdSupport'
  
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/BlueCatsSDK/"' }

  s.ios.dependency 'RestKit', '~> 0.22.0'
  s.ios.dependency 'CocoaLumberjack', '~> 1.6.4'
  s.ios.dependency 'MulticastDelegate', '~> 0.0.1.1'

  s.prefix_header_contents = <<-EOS
#import <Availability.h>

#define _AFNETWORKING_PIN_SSL_CERTIFICATES_

#if __IPHONE_OS_VERSION_MIN_REQUIRED
  #import <SystemConfiguration/SystemConfiguration.h>
  #import <MobileCoreServices/MobileCoreServices.h>
  #import <Security/Security.h>
#else
  #import <SystemConfiguration/SystemConfiguration.h>
  #import <CoreServices/CoreServices.h>
  #import <Security/Security.h>
#endif
EOS

end
