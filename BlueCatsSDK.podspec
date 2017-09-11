Pod::Spec.new do |s|
  s.name     = 'BlueCatsSDK'
  s.version  = '2.0.3'
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
              All text and design is copyright © 2013-2017 BlueCats Australia Pty Ltd.

              All rights reserved.

              https://bluecats.com/tos/
    LICENSE
  }
  s.summary  = 'BlueCatsSDK for micro-location.'
  s.homepage = 'http://www.bluecats.com'
  s.authors   = { 'BlueCats' => 'theteam@bluecats.com' }
  s.source   = { :git => 'https://github.com/bluecats/bluecats-ios-sdk.git', :tag => '2.0.3'  }
  s.platform = :ios, '8.0'
  s.public_header_files = 'Headers/*.h'
  s.source_files = ['Headers/*.h']
  s.vendored_libraries = 'libBlueCatsSDK.a'
  s.requires_arc = true
  s.ios.deployment_target = '8.0'
  s.frameworks = 'SystemConfiguration', 'CoreBluetooth', 'MobileCoreServices', 'CoreGraphics', 'CoreLocation', 'AdSupport', 'CoreData'
  
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/BlueCatsSDK/"', 'OTHER_LDFLAGS' => '$(inherited) "-ObjC"'}
end
