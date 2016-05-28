//
//  LP2ViewController.h
//  libpomelo2
//
//  Created by Felipe Cavalcanti on 05/28/2016.
//  Copyright (c) 2016 Felipe Cavalcanti. All rights reserved.
//

@import UIKit;

@interface LP2ViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIButton *connectButton;
@property (weak, nonatomic) IBOutlet UITextField *serverAddressTF;
@property (weak, nonatomic) IBOutlet UITextField *routeTF;
@property (weak, nonatomic) IBOutlet UILabel *responseLabel;
@property (weak, nonatomic) IBOutlet UIButton *requestButton;
@property (weak, nonatomic) IBOutlet UILabel *isConnectedLabel;

@end
