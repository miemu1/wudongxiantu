int permit_recruit(object ob)
{
        if( ob->query("detach/ɢ��") || 
            ob->query("betrayer/ɢ��") )
        {
                command("say �뿪��ɢ�޾Ͳ�Ҫ�ٻ�����");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���²��Ҳ��ţ�����ɢ����޵ľ����������ˡ�");
                return 0;
        }

        if( ob->query("family/family_name") && 
            ob->query("family/family_name") != "ɢ��" )
        {
                command("say ������ʦ�����Ͳ�Ҫ������ɢ���ˣ�");
                return 0;
        }

        return 1;
}