struct VS_INPUT
{
	float4 pos : POSITION;
	float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 pos : SV_POSITION;
	float2 uv : TEXCOORD;
};

struct FS_OUTPUT
{
	float4 color : COLOR;
};

sampler2D _MainTex : register(s0);
float4 _Color;
float4x4 mvp;

VS_OUTPUT VS(VS_INPUT vertex)
{
	VS_OUTPUT fragment;
	fragment.pos = mul(vertex.pos, mvp);
	fragment.uv = vertex.uv;
	return fragment;
}

FS_OUTPUT FS(VS_OUTPUT fragment)
{
	FS_OUTPUT pixel;
	pixel.color = tex2D(_MainTex, fragment.uv) * _Color;
	return pixel;
}

technique RedColor
{
	pass Pass0
	{
		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 FS();
	}
}