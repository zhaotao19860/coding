package main

import (
	"encoding/json"
	"fmt"
)

type PrivateZone struct {
	ConfType     string `json:"-"`
	OptType      int    `json:"-"`
	ZoneID       string
	ZoneSuffix   string
	Version      int64
	ZoneName     string
	RetryRecurse bool
	VPCs         map[string][]string
}

func main() {
	var pz PrivateZone
	pz.ZoneID = "zone-2imz3kfjk0"
	pz.ZoneSuffix = "2imz3kfjk0"
	pz.Version = 2
	pz.ZoneName = "1014-1.com"
	pz.RetryRecurse = true
	vpcs := make(map[string][]string)
	vpcs["cn-east"] = []string{"vpc-2ujb6yv7se", "vpc-sl7azz9abk", "vpc-gd1t0dwdnw", "vpc-xvmjlhtgm0", "vpc-dbr397xvsy"}
	vpcs["cn-west"] = []string{"vpc-2ujb6yv7se", "vpc-sl7azz9abk", "vpc-gd1t0dwdnw", "vpc-xvmjlhtgm0", "vpc-dbr397xvsy"}
	pz.VPCs = vpcs

	str, err := json.MarshalIndent(pz, "", "    ")
	if err != nil {
		fmt.Println("private zone formate error.")
	} else {
		fmt.Println(string(str))
	}
}
