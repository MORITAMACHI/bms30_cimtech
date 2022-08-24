<?php
/*
 * パスワード変更のためのModel
 * changePassword.phpに呼び出される
 * 作成者：武田
 */

class changePassword
{

    /**
     * フォームからの入力確認を行う関数
     *
     * @param
     *            $user
     * @return string/boolean
     */
    function checkParameter($user)
    {
        if ($_POST['change']) { // パスワード変更ボタン押下時
            if (empty($_POST['old']) || empty($_POST['new1']) || empty($_POST['new2'])) {
                return '入力されていません。全て入力してください';
            } else if ($_POST['old'] != $_SESSION['userInfo']['password']) {
                return '旧パスワードが一致しません。';
            } else if ($_POST['new1'] != $_POST['new2']) {
                return '新しいパスワードが一致しません。';
            }
            elseif ($this->searchUserid($_POST['userid']) === 0) {
                // 更新対象のデータがあるか確認
                return '選択されたユーザーIDは存在しません。';
            } else {
                if ($this->updatePass($_POST['new1'], $_POST['userid'])) {
                    return true;
                } else {
                    return 'パスワード更新に失敗しました。';
                }
            }
        }else{
            return false;
        }
    }

    /**
     * パスワードを更新する関数
     *
     * @param String $userid
     * @return boolean
     */
    public function updatePass($password, $userid)
    {

        $sql = "update userinfo set password = '{$password}' where user = '{$userid}'";
        $result = executeQuery($db,$sql);


        return $result;
    }

    /**
     * user情報があるか確認する関数
     *
     * @return int
     */
    public function searchUserid($userid)
    {

        $sql = "select * from userinfo where user = '{$userid}'";
        $result = executeQuery($db,$sql);

        // 行数を返す
//         return mysqli_num_rows($result);
        return $result;

    }

    // ユーザーのデータをインスタンス化して取得
    // @return Userｵﾌﾞｼﾞｪ
    function getUser($user){

        // インスタンスにセット
        if(isset($_POST['change'])){    // 変更ボタン押下時
            $user->setUser($_POST['userid']);
        }else{
            return false;
        }

        //$sql
        $result = $this->searchUserid($user->getUser());  //旧パスワードを取得（セッションに保存されてるのと同じ）

        $row = mysqli_fetch_array($result); //データベースから配列の形で取得

        if(mysqli_num_rows($result) !== 0){    // 成功の場合、他のユーザー情報も取得

            //var_dump($row['password']); //NULL

             $user->setPassword($row["password"]);
        }

        //結果保持用メモリを開放する
        mysqli_free_result($result);

        return $user;


    }
}
?>
