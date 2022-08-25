<?php
class deleteBook{

    //データ取得　オブジェクト
    public function getForm($books){

//         if (isset($_POST["kekka"])) {
//             //書籍番号
//             if(isset($_POST['isbn'])){
//                 $books->setIsbn($_POST['isbn']);
//             }
//             //本のタイトル
//             if(isset($_POST['title'])){
//                 $books->setTitle($_POST['title']);
//             }
//             //価格
//             if(isset($_POST['price'])){
//                 $books->setPrice($_POST['price']);
//             }


//             return $books;
//         }
    }

    //削除対象の書籍情報の有無を検索
    public function deleteData($db,$book){

        if(isset($_POST["isbn"])){
            $isbn = $_POST["isbn"];
        }else{
            $isbn = $_GET["isbn"];
        }

        $sql = "SELECT * FROM bookinfo WHERE isbn ='{$isbn}'";
        $result = executeQuery($db,$sql);

        if ($result) {

        //検索結果から結果セットの行数、書籍の情報(タイトルと価格)を取得
        $row = mysqli_fetch_array($result);

        $title=$row['title'];
        $price=$row['price'];

        $book->setIsbn($isbn);
        $book->setTitle($title);
        $book->setPrice($price);



            return $book;
        }else{
            return false;
        }



        //リソース解放
        mysqli_free_result($result);

//         return $book;
    }


    //書籍削除
    public function delete($db,$book){

        if($book!==false){

            //削除処理を実行
            $sql = "DELETE FROM bookinfo WHERE isbn ='{$book->getIsbn()}'";
            executeQuery($db,$sql);


            return $book;
        }

            }
    }







?>