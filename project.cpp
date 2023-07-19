//Begin page main
int* activeSites;
bool isX ;
bool isY ;

void init(){
    activeSites=game.GetActiveSites();
}

bool IsInSites(int x, int y) {
  isX = false;
  isY = false;
  for (int index1 = 0; index1 <= 2; index1++) {
    if (x == activeSites[index1]) {
      isX = true;
    }
    if (y == activeSites[index1]) {
      isY = true;
    }
  }
  return (isX && isY);
}

void MoveCollectMoveCollect(int site1, int site2) {
    game.MoveToSiteVoid(site1);
    game.CollectVoid();
    game.MoveToSiteVoid(site2);
    game.CollectVoid();    
}

void MoveCollectMoveDuplicate(int site1, int site2){
    game.MoveToSiteVoid(site1);
    game.CollectVoid();
    game.MoveToSiteVoid(site2);
    game.DuplicateVoid();
}

void loop(){   
     if (IsInSites(4, 6)) { 
        MoveCollectMoveDuplicate(4, 6);
     } else if(IsInSites(3, 6)) {
         MoveCollectMoveDuplicate(3, 6);
         game.CollectVoid();        
    } else if(IsInSites(4, 5)) {
         MoveCollectMoveDuplicate(5, 4);
         game.CollectVoid();
    } else if(IsInSites(2, 8)) {
        MoveCollectMoveDuplicate(2, 8);
        game.CollectVoid();         
    } else if(IsInSites(2, 6)) {
        game.MoveToSiteVoid(2);    
        game.CollectVoid();
        game.DuplicateVoid();
        game.MoveToSiteVoid(6);
        game.DuplicateVoid();        
    } else if (IsInSites(3, 8)) { 
        MoveCollectMoveDuplicate(3, 8);
    } else if(IsInSites(2, 4)) {
        MoveCollectMoveCollect(2, 4);
        game.DuplicateVoid();
    } else if(IsInSites(3, 5)) {
        MoveCollectMoveCollect(5, 3);
        game.DuplicateVoid();
    } else if(IsInSites(4, 8)) {
        game.MoveToSiteVoid(4);
        game.CollectVoid();
        game.DuplicateVoid();
        game.MoveToSiteVoid(0);
        game.DepositSamplesVoid();
        game.MoveToSiteVoid(8);
        game.CollectVoid();
    } else if(IsInSites(3, 7)) {
        MoveCollectMoveDuplicate(7, 3);
        game.CollectVoid();
    } else if (activeSites[0] == 1) {
        if (activeSites[1] == 2 && activeSites[2] == 3) {
            MoveCollectMoveCollect(1, 3);
            game.DuplicateVoid();
            game.MoveToSiteVoid(2);
            game.DuplicateVoid();
        } else if (activeSites[1] == 2 && activeSites[2] == 9) {
            MoveCollectMoveCollect(1, 9);
            game.MoveToSiteVoid(2);
            game.CollectVoid();
            game.DuplicateVoid();
        } else if (activeSites[1] == 3 && activeSites[2] == 4) {
            MoveCollectMoveCollect(1, 4);
            game.MoveToSiteVoid(3);
            game.CollectVoid();
            game.DuplicateVoid();
        } else if (activeSites[1] == 4 && activeSites[2] == 7) {
            game.MoveToSiteVoid(4);
            game.CollectVoid();
            game.DuplicateVoid();
            game.MoveToSiteVoid(0);
            game.DepositSamplesVoid();
            game.MoveToSiteVoid(1);
            game.CollectVoid();
            game.MoveToSiteVoid(7);
            game.CollectVoid();
        } else if (activeSites[1] == 6 && activeSites[2] == 9) {
            MoveCollectMoveDuplicate(1, 9);
            game.CollectVoid();
            game.MoveToSiteVoid(6);
            game.CollectVoid();
        }
    } else if (activeSites[0] == 2) {
        if (activeSites[1] == 3 && activeSites[2] == 9) {
            MoveCollectMoveCollect(9, 3);
            game.MoveToSiteVoid(2);
            game.DuplicateVoid();
        } else if (activeSites[1] == 5 && activeSites[2] == 7) {
            MoveCollectMoveCollect(5, 7);
            game.MoveToSiteVoid(2);
            game.DuplicateVoid();
        } else if (activeSites[1] == 5 && activeSites[2] == 9) {
            MoveCollectMoveDuplicate(2, 5);
            game.CollectVoid();
            game.MoveToSiteVoid(0);
            game.DepositSamplesVoid();            
            game.MoveToSiteVoid(9);
            game.CollectVoid();
        }
    } else if (activeSites[0] == 3 && activeSites[1] == 4 && activeSites[2] == 9) {
        MoveCollectMoveDuplicate(4, 3);
        game.CollectVoid();
        game.MoveToSiteVoid(9);
        game.CollectVoid();
    } else if (activeSites[0] == 7 && activeSites[1] == 8 && activeSites[2] == 9) {
        MoveCollectMoveCollect(7, 8);
        game.MoveToSiteVoid(0);
        game.DepositSamplesVoid();
        game.MoveToSiteVoid(9);
        game.CollectVoid();        
    } else {
        DEBUG(( "!!!!!!!!!!!!!!!!!      Did not match any criteria      !!!!!!!!!!!!!!!!!" ));        
    }
    
    game.MoveToSiteVoid(0);
    game.DepositSamplesVoid();
    game.EndGame();    
}







//End page main
