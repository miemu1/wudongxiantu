// check recruit  
//by y1
int permit_recruit(object ob)
{
              if (ob->query("detach/���Ƴ�") || ob->query("betrayer/���Ƴ�"))
        {
                command("say �㵱���Ȼ�Ѿ��뿪���ǣ����ںα���Ҫ������");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say �Ұ��Ƴ���С������Ҳ��������������ı�������֮ͽ��");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "���Ƴ�" )

        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬�������ǰ��ƳǸ��");
                return 0;
        }

        return 1;
}




 