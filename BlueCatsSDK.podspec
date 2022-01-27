Pod::Spec.new do |s|
  s.name     = 'BlueCatsSDK'
  s.version  = '2.2.0'
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
              All text and design is copyright © 2013-2019 BlueCats Australia Pty Ltd.
              All rights reserved.
              https://bluecats.com/tos/
    LICENSE
  }
  s.summary  = 'BlueCatsSDK for micro-location.'
  s.homepage = 'http://www.bluecats.com'
  s.authors   = { 'BlueCats' => 'theteam@bluecats.com' }
  s.source   = { :http => 'https://downloads.apps.bluecats.com/sdks/ios/bluecats-ios-sdk-2.2.0.zip'}
  s.platform = :ios, '9.0'
  s.public_header_files = 'Headers/*.h'
  s.source_files = ['Headers/*.h']
  s.vendored_libraries = 'libBlueCatsSDK.a'
  s.requires_arc = true
  s.ios.deployment_target = '9.0'
  s.frameworks = 'SystemConfiguration', 'CoreBluetooth', 'MobileCoreServices', 'CoreGraphics', 'CoreLocation', 'AdSupport', 'CoreData'
  
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/BlueCatsSDK/"', 'OTHER_LDFLAGS' => '$(inherited) "-ObjC"'}
end