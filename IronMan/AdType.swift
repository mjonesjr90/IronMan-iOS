//
//  AdType.swift
//  IronMan
//
//  Created by Malcom Jones on 2/27/18.
//  Copyright © 2018 Malcom Jones. All rights reserved.
//

import Foundation
import UIKit

class AdType {
    //MARK: Properties
    var name: String
    var id: String
    var size: CGSize
    var hb: Bool
    var ssp: String
    
    //MARK: Initialization
    init(name: String, id: String, size: CGSize, hb: Bool, ssp: String) {
        self.name = name
        self.id = id
        self.size = size
        self.hb = hb
        self.ssp = ssp
    }
}
