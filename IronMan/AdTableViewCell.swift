//
//  AdTableViewCell.swift
//  IronMan
//
//  Created by Malcom Jones on 2/23/18.
//  Copyright © 2018 Malcom Jones. All rights reserved.
//

import UIKit

class AdTableViewCell: UITableViewCell {

    //MARK: Properties
    @IBOutlet weak var adTypeLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
