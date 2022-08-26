<?php
class insertBook{

    //データ取得　オブジェクト
    public function getForm($books){

        if (isset($_POST["kekka"])) {
            //書籍番号
            if(isset($_POST['isbn'])){
                $books->setIsbn($_POST['isbn']);
            }
            //本のタイトル
            if(isset($_POST['title'])){
                $books->setTitle($_POST['title']);
            }
            //価格
            if(isset($_POST['price'])){
                $books->setPrice($_POST['price']);
            }
//             //権限
//             if(isset($_POST['authority'])){
//                 $books->setAuthority($_POST['authority']);
//             }

        return $books;
        }
    }




    //書籍登録
    public function insert($db,$book){
        if (isset($_POST["kekka"])) {

        $isbn = $book->getIsbn();
        $title =$book->getTitle();
        $price =$book->getPrice();

        //echo "ISBN=".$isbn." Title=".$title." 価格=".$price;

        $sql = "INSERT INTO bookinfo VALUES('{$isbn}','{$title}',{$price})";
        executeQuery($db,$sql);

        return $book;

        }
    }

//     public function insertBooks($book){

//         if (isset($_POST["kekka"])) {

//             $isbn = $_POST['isbn'];
//             $title = $_POST['title'];
//             $price = $_POST['price'];

//             //echo "ISBN=".$isbn." Title=".$title." 価格=".$price;

//             $sql = "INSERT INTO bookinfo VALUES('{$isbn}','{$title}',{$price})";
//             executeQuery($sql);
//         }




}


?>