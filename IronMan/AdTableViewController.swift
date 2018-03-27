//
//  AdTableViewController.swift
//  IronMan
//
//  Created by Malcom Jones on 2/23/18.
//  Copyright © 2018 Malcom Jones. All rights reserved.
//

import UIKit
import os.log

class AdTableViewController: UITableViewController {

    // MARK: Properties
    var adTypes = [AdType]()
    
    
    // MARK: Overridden Functions
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Load ad types into table view list
        loadAdTypes()

        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: Private Methods
    private func loadAdTypes() {
        
        // Create adTypes here
        // This will be loaded into Tableview and populate ViewController upon selection
        // ssp parameter denotes whether to call onemobile, mopub, dfp, etc.
        let onemobile_banner = AdType(name:"ONE Mobile Banner", id:"banner_homescreen", size:CGSize(width: 320, height: 50), hb:false, ssp: "onemobile")
        let onemobile_mrec = AdType(name:"ONE Mobile MREC", id:"mrec", size:CGSize(width: 300, height: 250), hb:false, ssp: "onemobile")
        let onemobile_sa_banner = AdType(name:"Super Auction Banner", id:"banner_homescreen_sa", size:CGSize(width: 320, height: 50), hb:true, ssp: "onemobile")
        let mopub_banner = AdType(name:"MoPub Banner", id:"8cbf99596fe4403abc52b5cae808a8f5", size:CGSize(width: 320, height: 50), hb:true, ssp: "mopub")
        
        adTypes += [onemobile_banner, onemobile_mrec, onemobile_sa_banner, mopub_banner]
    }
    
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return adTypes.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // Table view cells are reused and should be dequeued using a cell identifier
        let cellIdentifier = "AdTableViewCell"
        
        guard let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier, for: indexPath) as? AdTableViewCell else {
            fatalError("The dequeued call is not an instance of AdTableViewCell")
        }
        
        // Get the right ad type
        let adType = adTypes[indexPath.row]

        // Configure the cell...
        cell.adTypeLabel.text = adType.name

        return cell
    }

    /*
    // Override to support conditional editing of the table view.
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }
    */

    /*
    // Override to support editing the table view.
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            // Delete the row from the data source
            tableView.deleteRows(at: [indexPath], with: .fade)
        } else if editingStyle == .insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
        }    
    }
    */

    /*
    // Override to support rearranging the table view.
    override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {

    }
    */

    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the item to be re-orderable.
        return true
    }
    */

    
    // MARK: - Navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        super.prepare(for: segue, sender: sender)
        switch(segue.identifier ?? ""){
        case "ShowAd":
            os_log("Attempting to show ad", log: OSLog.default,type: .debug)
            
            // Get the destination view controller
            guard let adViewController = segue.destination as? AdViewController else {
                    fatalError("Unexpected destination: \(segue.destination)")
            }
            
            // Get the selected cell (ad type)
            guard let selectedAdCell = sender as? AdTableViewCell else {
                fatalError("Unexpected sender: \(String(describing: sender))")
            }
            
            // Get the indexpath of the cell (ad type)
            guard let  indexPath = tableView.indexPath(for: selectedAdCell) else {
                fatalError("The selected cell is not being displayed by the table")
            }
            
            let selectedAdType = adTypes[indexPath.row]
            
            //Set ad type of view controller to the correct ad type
            adViewController.adType = selectedAdType
        default:
            fatalError("Undexpected segue identifier; \(String(describing: segue.identifier))")
        }
    }
    

}
