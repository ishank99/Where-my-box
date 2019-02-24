0#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define debug1(x) cout << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";

#define mod 1000000007
map<int, vector<int> > mp;

int main()
{
	freopen("pgmimg.pgm", "r", stdin);
	string type; cin >> type;
    int indexp = -1;
	int ID;
    int row, col, i, j;
    cin >> col >> row;
    int max_pix; cin >> max_pix;
    srand(time(NULL));
    int arr[row][col] = {};
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            //arr[i][j] = rand()%2;
            cin >> arr[i][j];
            if(arr[i][j] == 0) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    int open = 0;
    vector<int> rack;
    for (j = 0; j < col; j++)
    {
        if (arr[0][j] == 0)
        {

            if (open == 1)
            {
                rack.pb(j);
                open = 0;
            }
        }
        else
        {
            if (open == 0)
            {
                open = 1;
                rack.pb(j);
            }
        }
    }
    if (open == 1)
        rack.pb(col);

    for (i = 0; i < rack.size(); i += 2)
    {   ///// vector rack has (x1, x2) or top level of racks.

        int curr_col = rack[i + 1] - rack[i];
        int curr[row][curr_col];
        memset(curr, 0, sizeof(curr)); //// CURRENT RACK ------- /////
        int ii, jj;
        int count = 0;

        for (ii = 1; ii < row - 1; ii++)
        {
            count = 0;
            for (jj = 1; jj < curr_col - 1; jj++)
            {
                if (arr[ii][jj + rack[i]] == 1)
                    count++;
                curr[ii][jj] = arr[ii][jj + rack[i]];
            }
            if (count == curr_col - 2)
            {
                for (int kk = 0; kk < curr_col - 1; kk++)
                {
                    curr[ii][kk] = 0;
                }
            }
        }

        /*
		for (ii = 0; ii < row; ii++)
        {
            for (jj = 0; jj < curr_col; jj++)
            {
                cout << curr[ii][jj] << " ";
            }
            cout << endl;
        }*/
        ///////////////////////////////////////////////////////////////////
        // FIND SHAPE IN EACH RACK

        int ip, jp;
        int r_size = row, c_size = curr_col;
        //int curr[r_size][c_size];
        for (ip = 0; ip < r_size; ip++)
        {
            for (jp = 0; jp < c_size; jp++)
            {
                if (curr[ip][jp] == 1)
                {
                    mp[indexp + 1].push_back(ip);
                    mp[indexp + 1].push_back(jp + rack[i]);
                    indexp++;
                    //findend(ip,jp,v,index,r_size,c_size);
                    int flagcp = 0;
                    int flagrp = 0;
                    int kp, lp;

                    for (kp = ip; kp < r_size; kp++)
                    {
                        if (curr[kp][jp] == 0)
                        {
                            flagrp = 1;
                            break;
                        }
                        if (curr[kp][jp] == 5)
                        {
                            continue;
                        }

                        for (lp = jp; lp < c_size; lp++)
                        {
                            if (curr[kp][lp] == 0)
                            {
                                flagcp = 1;
                                break;
                            }
                            curr[kp][lp] = 5;
                        }
                    }
                    if (flagrp == 1)
                    {
                        mp[indexp].push_back(kp - 1);
                    }
                    else
                    {
                        mp[indexp].push_back(kp);
                    }

                    if (flagcp == 1)
                    {
                        mp[indexp].push_back(lp - 1 + rack[i]);
                    }
                    else
                    {
                        mp[indexp].push_back(lp + rack[i]);
                    }
                }
            }

            //map<int,vector<int> >::iterator it=mp.begin();
        }
        map<int, vector<int > >::iterator it = mp.begin();
        int xa, ya; int xb ,yb;
	    vector< pair < pair<int, int >, pair<int, int > > > square, rect;

	    freopen("output.txt", "w", stdout);

	    ID = 1;
        for (; it != mp.end(); it++)
        {
            xa = it->second[0];
		    ya = it->second[1];
		    xb = it->second[2];
		    yb = it->second[3];
		    if(abs(xa-xb) == abs(ya-yb)) {
	        	square.pb({{xa, ya}, {xb, yb}});

	        	cout<<ID<<" Square      "<<xa<<' '<<ya<<' '<<xb<<' '<<yb<<'\n';

	        	ID++;
			}
			else {
				rect.pb({{xa, ya}, {xb, yb}});

				cout<<ID<<" Rectangle   "<<xa<<' '<<ya<<' '<<xb<<' '<<yb<<'\n';

				ID++;
			}
        }

        // start reading from formdata.txt
        freopen("formdata.txt", "r", stdin);
        int query;
		cin >> query;

		int len, width;
		cin >> len >> width;

		freopen("outres.txt", "w", stdout);
		if(query == 1){ //square
			int flag = 0;
			for(int q = 0; q<square.size(); q++) {

				if(square[q].se.fi - square[q].fi.fi == len-1) {

					cout<<"YES\n";

					flag == 1;
					break;
				}
			}
			if(!flag) {

				cout<<"NO\n";

			}
		}
		else if(query == 2) { //rectangle
			int flag = 0;
			for(int q = 0; q<rect.size(); q++) {
				if(rect[q].se.fi - rect[q].fi.fi == len-1 and rect[q].se.se - rect[q].fi.se == width-1) {

					cout<<"YES";

					flag = 1;
					break;
				}
			}
			if(!flag) {

				cout<<"NO";

			}
		}

        ///////////////////////////////////////////////////////////////////
    }
    return 0;
}
/*
Master TC
8 15
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
1 0 1 1 0 0 1 0 1 0 1 1 0 0 1
1 0 1 1 0 0 1 0 1 0 1 1 0 0 1
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
1 0 0 1 1 1 1 0 1 0 0 1 1 1 1
1 0 0 1 1 1 1 0 1 0 0 1 1 1 1
1 0 0 1 1 1 1 0 1 0 0 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
*/
