<?php

class ShowCart{

    //削除リンクから戻ってきている場合、書籍情報を削除
    public function DeleteBook(){

        if(isset($_GET['delno'])){
            $isbn = $_GET['delno'];

            foreach($_SESSION['cartInfo'] as $key => $val){
                $obj = $val;
                if($obj->getIsbn() == $isbn){
                    $index = $key;
                }
            }

            unset($_SESSION['cartInfo'][$index]);

//             unset($_SESSION['cartInfo'][$_GET['delno']]);
        }
    }

}
?>
