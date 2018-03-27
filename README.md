# IronMan-iOS
Test platform for ONE Mobile, DFP, and MoPub

## Prerequisites

To further develop this app, you will need:
- Xcode 9.2+
- macOS 10.12.6+

## Application Architecture

This app uses the conventional Apple iOS Model-View-Controller design pattern. Some key components are outlined below:

#### AdType
Defines an `adTYype` object that contains the following properties

```swift
var name: String    //Display name
var id: String      //placementID, adUnitID, etc.
var size: CGSize    //ad size using width and height
var hb: Bool        //is header bidding? (Super Auction)
var ssp: String     //onemobile, mopub, dfp, etc.
```

#### AdTableViewController
Loads ad information and defines how the segue from the main screen (TableView) to the AdView occurs.

`private func loadAdTypes()` creates an array of `adTypes`

The `adType.name` is used to populate the main screen rows and upon selection, the `adType` is passed on to the AdViewController.

#### AdViewController
This ViewController determines which ads are displayed in the app. An `adType` object is passed to the ViewController, is parsed, and the appropriate ad call is made.

`override func viewDidLoad()` identifies which SSP is making the ad request through `adType.ssp` and parses the object to get the required information.

#### AppDelegate
This Delegate initializes the MMSDK on app startup.

## Integrating New Ad Types
To add a new ad type, create a new instance of `adType`  within the `loadAdTypes()` function of AdTableViewController and ad it to the `adTypes` array.

```swift
let my_new_ad = AdType(name: String, id: String, size: CGSize, hb: Bool, ssp: String)

adTypes += [my_new_ad]
```

## Authors
**Malcom Jones Jr.** - [MalcomJones.com](https://malcomjones.com)
