class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        string res;
        vector<string> final_res;
        sort(folder.begin(),folder.end());
        final_res.push_back(folder[0]);
        string lastfolder;
        for(int i=1; i<folder.size(); i++) {
            lastfolder = final_res.back()+'/';
            //now check if the folder[i] starts with the lastfolder, if yes then ignore and if not update the lastfolder
            bool flag = true;
            string f = folder[i];
            for(int j=0; j<lastfolder.length(); j++) {
                if(lastfolder[j] != f[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) continue;
            else final_res.push_back(folder[i]);
        }
        return final_res;
    }
};