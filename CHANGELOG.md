
  
### Version 0.0.1 (March 12, 2013)

### Version 0.0.2 (July 23, 2013)

##### Updates to the BlueCats SDK
  - Added support for Markers

#### Distribution and Documentation Updates
  - Added BlueCats Sample Application

### Version 0.1.1 (January 28, 2014)
  - Improved support for background scanning and notifications

### Version 0.1.4 (April 29, 2014)
 - Updates to local notification scheduling via the SDK to make it more flexible. When scheduling a local notification via the SDK:
    - Site is optional, so a notification can be scheduled to trigger in any site
    - Categories are matched by name
    - Notification will trigger in a requested proximity, or closer. For example a notification for 'Far' proximity will trigger in Immediate, Near or Far proximities. This improves reliability of notifications being triggered successfully when an app is in the background.

### Version 0.3.2 (September 29, 2014)
  - iOS 8.0 Support

### Version 0.3.4 (November 5, 2014)
  - Secure mode performance and stability updates

### Version 0.4.0 (December 5, 2014)
  - Removes external dependencies (RestKit)

### Version 0.4.1 (January 7, 2015)
  - Performance improvements and bug fixes

### Version 0.4.2 (March 3, 2015)
  - Background secure mode performance improvements

### Version 0.5.0 (March 5, 2015)
  - Performance and stability improvements for visit tracking in background
  - Added option to disable scanning in background
  - Support querying local storage for visit history
  
### Version 0.6.0 (August 26, 2015)
  - Zone monitoring and the [BlueCats-OtherLevels iOS SDK extension](https://github.com/bluecats/bluecats-otherlevels-ios-sdkext) introduced to support the OtherLevels platform
  - Beacon network access control
  - Lasso integration
  - Additional and updated event filters
  - Optimized event processing
  - Performance and stability improvements
   
### Version 0.6.2 (September 1, 2015)
  - Fixed reassemble block data
  - Added ignore case option when finding custom value by key
