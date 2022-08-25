<?php
class detailBook{

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


            return $books;
        }
    }

    //書籍情報の有無を検索
    public function detailData($db,$book){

        if(isset($_POST["isbn"])){
            $isbn = $_POST["isbn"];
        }else{
            $isbn = $_GET["isbn"];
        }

        $sql = "SELECT * FROM bookinfo WHERE isbn ='{$isbn}'";
        $result = executeQuery($db,$sql);


        //検索結果から結果セットの行数、書籍の情報(タイトルと価格)を取得
        $row = mysqli_fetch_array($result);

        $title=$row['title'];
        $price=$row['price'];

        $book->setIsbn($isbn);
        $book->setTitle($title);
        $book->setPrice($price);

        //リソース解放
        mysqli_free_result($result);

        return $book;

        }
    }

?>