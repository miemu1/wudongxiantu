// kunlun.h

int permit_recruit(object ob)
{       
        if( ob->query("detach/��ɽ��") ||
            ob->query("betrayer/��ɽ��") )
        {
                command("say ���㻹����������ɽ�ɣ����ҹ�����");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���²��Ҳ��ţ�����ʹ�����������ˡ�");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "��ɽ��" )
        {
                command("say ���¼�������ʦָ�㣬����������ɽ����ʲô��");
                return 0;
        }

        return 1;
}
