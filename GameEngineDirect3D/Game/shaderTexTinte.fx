struct VS_INPUT
{
	float4 pos : POSITION;
	float3 normal : NORMAL;
	float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 pos : SV_POSITION;
	float2 uv : TEXCOORD;
	float3 normal : TEXCOORD2;
	float4 lightColor : TEXCOORD3;
};

struct FS_OUTPUT
{
	float4 color : COLOR; 
};

//sampler2D _MainTex : register(s0);
float4x4 texMatrix;
texture tex;
float4 _Color;
float4x4 mvp;
float4x4 rotMat;
float3 lightDir;
float4 lightCol;
float4 ambientCol;
sampler2D _MainTex = sampler_state
{
	texture = tex;
	MagFilter = LINEAR;
};
float num;

//Esta función recibe la normal del objeto y calcula 
//la intensidad de la luz ante dicha normal
float4 getLight(float3 normal)
{
	//Diffuse nos dice que tan paralela es la dirección de la luz
	//con respecto a la normal del objeto, indicando la intensidad de la luz
	//Esto es gracias a que el dot product compara ambas direcciones
	float diffuse = dot(lightDir, normal);

	//Retorno el color de la luz especificado por parametros multiplicado
	//por la intensidad de la luz, asi tengo el color tan intenso como la luz
	//También le sumamos la luz ambiente para simular los rebotes de la luz
	//sobre el ambiente
	return ambientCol + lightCol * diffuse;
}

VS_OUTPUT VS(VS_INPUT vertex)
{
	VS_OUTPUT fragment;
	fragment.pos = mul(vertex.pos, mvp);
	float4 temp = mul(float4(vertex.uv.x, vertex.uv.y, 1.0f, 1.0f), texMatrix);
	fragment.uv = temp.xy;
	fragment.normal = mul(vertex.normal, rotMat);
	fragment.lightColor = getLight(fragment.normal);
	return fragment;
}

FS_OUTPUT FS(VS_OUTPUT fragment)
{
	FS_OUTPUT pixel;
	pixel.color = tex2D(_MainTex, fragment.uv) * _Color * num * 2 * fragment.lightColor;
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
