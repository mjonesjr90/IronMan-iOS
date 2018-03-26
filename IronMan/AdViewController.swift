//
//  ViewController.swift
//  IronMan
//
//  Created by Malcom Jones on 2/21/18.
//  Copyright © 2018 Malcom Jones. All rights reserved.
//

import UIKit
import os.log

class AdViewController: UIViewController, MMInlineDelegate, MPAdViewDelegate{

    //MARK: Properties
    @IBOutlet weak var adContainer: UIView!
    
    //MARK: MM Properties
    var adType: AdType!
    var inlineAd: MMInlineAd!
    var mpAdView: MPAdView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
//        if adType.hb {
//            //Call RequestBid API
//        }
        if adType.ssp == "onemobile" {
            os_log("This is a ONE Mobile request", log: OSLog.default,type: .debug)
            self.title = adType.name
            self.inlineAd = MMInlineAd(placementId: adType.id, size: adType.size)
            self.inlineAd.delegate = self
            self.inlineAd.refreshInterval = 30
            self.adContainer!.addSubview(self.inlineAd.view)
            self.inlineAd.request(nil)
        }
        if adType.ssp == "mopub" {
            os_log("This is a MoPub request", log: OSLog.default,type: .debug)
            self.title = adType.name
            self.mpAdView = MPAdView(adUnitId: adType.id, size: adType.size)
            self.mpAdView.delegate = self
            self.adContainer!.addSubview(self.mpAdView)
            self.mpAdView.loadAd()
        }
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    //MARK: Inline Delegate Methods
    func viewControllerForPresentingModalView() -> UIViewController {
        return self
    }

    //MARK: MoPub Ad listener methods
//    func adViewDidLoadAd(_ view: MPAdView!) {
//        print("Inline request succeeded.")
//        os_log("Inline request succeeded", log: OSLog.default, type: .debug)
//    }
//    
//    func adViewDidFail(toLoadAd view: MPAdView!) {
//        print("Inline request failed.")
//        os_log("Inline request failed", log: OSLog.default, type: .debug)
//    }
    
    //MARK: MMSDK Ad listener methods
    func inlineAdRequestDidSucceed(_ ad: MMInlineAd) {
        print("Inline request succeeded.")
    }
    
    func inlineAd(_ ad: MMInlineAd, requestDidFailWithError error: Error) {
        print("Inline ad failed: \(error).")
    }
    
    func inlineAdContentTapped(_ ad: MMInlineAd){
        print("Inline ad tapped.")
    }
    
    func willResizeTo(ad: MMInlineAd, frame: CGRect, isClosing: Bool) {
        print("Inline ad is \(isClosing ? "closing" : "resizing") and will resize to frame \(NSStringFromCGRect(frame)).")
    }
    
    func didResizeTo(ad: MMInlineAd, frame: CGRect, isClosing: Bool) {
        print("Inline ad is \(isClosing ? "closing" : "resizing") and did resize to frame \(NSStringFromCGRect(frame)).")
    }
    
    func inlineAdWillPresentModal(_ ad: MMInlineAd){
        print("Inline ad will present modal view.")
    }
    
    func inlineAdDidPresentModal(_ ad: MMInlineAd){
        print("Inline ad did present modal view.")
    }
    
    func inlineAdWillCloseModal(_ ad: MMInlineAd){
        print("Inline ad will close modal view.")
    }
    
    func inlineAdDidCloseModal(_ ad: MMInlineAd){
        print("Inline ad did close modal view.")
    }
    
    func inlineAdWillLeaveApplication(_ ad: MMInlineAd){
        print("Inline ad will leave application.")
    }
    
    func inlineAdAbortDidSucceed(_ ad: MMInlineAd) {
        print("Inline ad did abort successfuly.")
    }
    
    func inlineAd(_ ad: MMInlineAd, abortDidFailWithError error: Error) {
        print("Inline ad did fail to abort: \(error).")
    }
}

    
    //MARK: Navigation
    
//    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
//        super.prepare(for: segue, sender: sender)
//    }

